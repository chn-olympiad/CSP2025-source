#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct no{
	int id,v;
}d1[N],d2[N],d3[N],a1[N],a2[N],a3[N];
int di1=0,di2=0,di3=0;long long ans=0;
bool f=0;int vis[N]={0,0,0,0};
bool cmp(no x,no y){
	return x.v>y.v;
}
void dfs(int x,long long ans1,int step){
	if(step==n+1){
		ans=max(ans,ans1);return;
	}
	if(x==0){
		dfs(1,0,1);
		dfs(2,0,1);
		dfs(3,0,1);
	}
	if(x==1){
		ans1+=a1[step].v;
		dfs(1,ans1,step+1);
		dfs(2,ans1,step+1);
		dfs(3,ans1,step+1);
	}
	if(x==2){
		ans1+=a2[step].v;
		dfs(1,ans1,step+1);
		dfs(2,ans1,step+1);
		dfs(3,ans1,step+1);
	}
	if(x==3){
		ans1+=a3[step].v;
		dfs(1,ans1,step+1);
		dfs(2,ans1,step+1);
		dfs(3,ans1,step+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof vis);
		memset(d1,0,sizeof d1);
		memset(d2,0,sizeof d2);
		memset(d3,0,sizeof d3);
		ans=0;long long j1=0,j2=0,j3=0;
		long long maxn=LLONG_MIN;
		scanf("%d",&n);int k=INT_MAX;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i].v,&a2[i].v,&a3[i].v);d1[i].id=i;d2[i].id=i;d3[i].id=i;d1[i].v=a1[i].v;d2[i].v=a2[i].v;d3[i].v=a3[i].v;
		}
			if(n<=30){
				dfs(0,0,0);
				cout<<ans<<endl;continue;
			}
			sort(d1+1,d1+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=d1[i].v;vis[d1[i].id]=1;
			}
			for(int i=n;i>=1;i--){
				if(vis[i]) continue;
				ans+=max(a2[i].v,a3[i].v);
			}
			maxn=max(ans,maxn);
			memset(vis,0,sizeof vis);
			ans=0;
			sort(d2+1,d2+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=d2[i].v;vis[d2[i].id]=1;
			}
			for(int i=n;i>=1;i--){
				if(vis[i]) continue;
				ans+=max(a1[i].v,a3[i].v);
			}
			maxn=max(ans,maxn);
			ans=0;
			memset(vis,0,sizeof vis);
			sort(d3+1,d3+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=d3[i].v;vis[d3[i].id]=1;
			}
			for(int i=n;i>=1;i--){
				if(vis[i]) continue;
				ans+=max(a2[i].v,a1[i].v);
			}
			maxn=max(ans,maxn);
			printf("%lld\n",maxn);
			
	}
	return 0;
} 
