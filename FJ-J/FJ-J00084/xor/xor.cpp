#include<bits/stdc++.h>
using namespace std;
long long n,k,t=1,p=0,q=0,a[500005][30],b[500005],c[500005],v[500005],ans=0;
void zax(long long x,long long y){
	t=1;
	p=0;
	q=0;
	while(t<=y){
		t*=2;
		q++;
	}
	a[x][0]=q;
	while(y!=0){
		if(y>=t){
			y-=t;
			a[x][q+1]=1;
		}
		t/=2;
		q--;
	}
}
bool zay(long long x,long long y){
	p=a[x][0];
	t=1;
	long long cnt=0;
	for(long long i=x;i<y;i++){
		p=max(p,a[i+1][0]);
	}
	for(long long i=0;i<p;i++){
		c[i]=0;
	}
	for(long long i=x;i<y;i++){
		for(long long j=1;j<=max(a[i][0],a[i+1][0]);j++){
			if(a[i][j]!=a[i+1][j]){
				c[j]=1;
     		}else{
     			c[j]=0;
			 }
		}
	}
	for(long long i=1;i<=p+1;i++){
		cnt+=c[i]*t;
		c[i]=0;
		t*=2;
	}
	if(cnt==k){
		for(long long i=x;i<=y;i++){
    		v[i]=1;
		}
		return 1;
	}else{
		for(long long i=x;i<=y;i++){
    		v[i]=0;
		}
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>b[i];
		a[i][0]=b[i];
		zax(i,b[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(j==i&&b[i]==k&&v[i]==0){
		    	v[i]=1;
				ans++;
			}
			if(v[i]==0&&v[j]==0&&i!=j){
				if(zay(i,j)){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
