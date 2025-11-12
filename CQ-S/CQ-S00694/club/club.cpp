#include<bits/stdc++.h>
using namespace std;
#define int long long

int t,n;
int ans=-1;
struct Node{
	int a1,a2,a3;
}f[100100];
void dfs(int u,int t,int cnt1,int cnt2,int cnt3){
	if(u>n){
		ans=max(ans,t);
		return;
	}
	if(cnt1+1<=n/2) dfs(u+1,t+f[u].a1,cnt1+1,cnt2,cnt3);
	if(cnt2+1<=n/2) dfs(u+1,t+f[u].a2,cnt1,cnt2+1,cnt3);
	if(cnt3+1<=n/2) dfs(u+1,t+f[u].a3,cnt1,cnt2,cnt3+1);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>f[i].a1>>f[i].a2>>f[i].a3;
		ans=-1;
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
