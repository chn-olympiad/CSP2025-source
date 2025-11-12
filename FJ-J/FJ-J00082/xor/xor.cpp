#include<bits/stdc++.h>
using namespace std;

long long a[1000005];
long long n,k;
long long vis[1000005];
long long sum1=0,sum=0;
long long ans=0;
long long t=1;
long long maxx=-1;
long long yh (long long x,long long y){
	long long b=1;
	long long sum=0;
	long long xx,yy;
	while(x>0 || y>0){
		xx=x%10;
		yy=y%10;
		if(xx==yy){
			b*=10;
		}else{
			sum+=1*b;
			b*=10;	
		}
	}
	b=1;
	return sum;
}
void dfs(long long ans,int l,int design,long long design2){
	if(design2==k){
		ans++;
		if(l==n){
			maxx=max(maxx,ans);
			return;
		}
	}
	for(int i=design;i<=n;i++){
		if(vis[i]==0){
			design2=yh(design2,a[i]);
			vis[i]=1;
		    dfs(ans,l++,i,design2);
		    vis[i]=2;
		}
	}
}
long long zh(long long a){
	long long b=a%2;
	sum+=b*t;
	t*=10;
	a/=2;
	if(a==1){
		sum+=b*t;
		t=1;
		return sum;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=zh(a[i]);
		if(a[i]==0){
			sum1++;
		}
	}
	if(k==0){
		cout<<sum1;
		return 0;
	}
	k=zh(k);
	dfs(0,0,1,1);
	cout<<maxx;
	return 0;
}
