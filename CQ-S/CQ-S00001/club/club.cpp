#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1e5+10; 
int t;
int n;
ll sum,ans;
struct node{
	ll a,b,c;
}x[N];
bool cmp(node x,node y){
	return x.a>y.a;
}
void dfs(int k,int a,int b,int c,ll res){
	if(k==n+1){
		ans=min(ans,res);
		return ;
	}
	if(res>=ans) return ;
	if(a) dfs(k+1,a-1,b,c,res+x[k].b+x[k].c);
	if(b) dfs(k+1,a,b-1,c,res+x[k].a+x[k].c);
	if(c) dfs(k+1,a,b,c-1,res+x[k].a+x[k].b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout)
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sum=0,ans=LONG_LONG_MAX;
		bool bf=false,cf=false;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x[i].a,&x[i].b,&x[i].c);
			if(x[i].b) bf=true;
			if(x[i].c) cf=true; 
			sum+=x[i].a+x[i].b+x[i].c;
		}
		if(!bf&&!cf){
			sort(x+1,x+1+n,cmp);
			ans=0;
			for(int i=1;i<=n/2;i++) ans+=x[i].a;
			printf("%lld\n",ans);
			continue;
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2&&j<=n-i;j++){
				if(n-i-j>n/2) continue;
				dfs(1,i,j,n-i-j,0);
			}
		}
		printf("%lld\n",sum-ans);
	}
	return 0;
}
