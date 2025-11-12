#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int t,n,ans;
struct Data{
	int a,b,c;
}a[MAXN];
void dfs(int k,int cnta,int cntb,int cntc,int cnt){
	ans=max(ans,cnt);
	if(k>n)return;
	if(cnta<n/2)dfs(k+1,cnta+1,cntb,cntc,cnt+a[k].a);
	if(cntb<n/2)dfs(k+1,cnta,cntb+1,cntc,cnt+a[k].b);
	if(cntc<n/2)dfs(k+1,cnta,cntb,cntc+1,cnt+a[k].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-0x3f3f3f3f;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
