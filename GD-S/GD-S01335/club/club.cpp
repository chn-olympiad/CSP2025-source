#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>


using namespace std;

long long a[100005],b[10005],c[10005],f[10005];
long long n,ans;
struct node{
	long long a,i,b;
}t[100005];
bool cmp(node x,node y){
	return (x.a+x.b)>(y.a+y.b);
}

void dfs(long long u){
	if(u>n){
		long long sum=0;
		long long c1=0,c2=0,c3=0;
		for(long long i=1;i<=n;i++){
			if(f[i]==1)c1++,sum+=a[i];
			if(f[i]==2)c2++,sum+=b[i];
			if(f[i]==3)c3++,sum+=c[i];
		}
		if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			ans=max(ans,sum);
		}
		return ;
	}
	f[u]=1;dfs(u+1);
	f[u]=2;dfs(u+1);
	f[u]=3;dfs(u+1);
}
long long T;
	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long A=1,B=1;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0)B=0;
			if(a[i]!=0)A=0;
			t[i].a=a[i],t[i].b=b[i],t[i].i=i;
		}
		if(n<=10){
			memset(f,0,sizeof(f));
			ans=0;
			dfs(1);
			cout<<ans<<endl;
			continue;
		}
		if(A){
			sort(a+1,a+n+1);
			long long sum=0;
			for(long long i=n/2+1;i<=n;i++)sum+=a[i];
			cout<<ans<<endl;
			continue;
		}
		if(B){
			long long as=0,c1=0,c2=0;
			sort(t+1,t+n+1,cmp);
			for(long long i=1;i<=n;i++){
				long long ii=t[i].i;
				if(i<=n/2){
					if(a[ii]>b[ii]){
						c1++;as+=a[ii];
					}else{
						c2++,as+=b[ii];
					}
				}else {
					if(a[ii]>b[ii]){
						if(c1<n/2){
							c1++;as+=a[ii];
						}else {
							c2++,as+=b[ii];
						}
						
					}else{
						if(c2<n/2)c2++,as+=b[ii];
						else c1++,as+=a[ii];
					}
				} 	
			}
			cout<<as<<endl;
		}
		
	}
	
	return 0;
} 



