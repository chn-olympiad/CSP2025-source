#include<bits/stdc++.h>
using namespace std;
long long ans=0;
struct p{
	long long a,b,c,f;
}c[100010];
long long n;
void dfs(long long cnt,long long k,long long x=0,long long y=0,long long z=0){
	if(k>=n){
		if(cnt>ans){
			ans=cnt;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&(x+1)<=n/2){
			dfs(cnt+c[k].a,k+1,x+1,y,z);
		}else if(i==2&&(y+1)<=n/2){
			dfs(cnt+c[k].b,k+1,x,y+1,z);
		}else if(i==3&&(z+1)<=n/2){
			dfs(cnt+c[k].c,k+1,x,y,z+1);
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		scanf("%lld",&n);
		ans=0;
		for(long long i=0;i<n;i++){
			scanf("%lld%lld%lld",&c[i].a,&c[i].b,&c[i].c);
			c[i].f=0;
		}
		dfs(0,0);
		cout<<ans<<"\n";
	}
	return 0;
} 