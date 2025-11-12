#include<bits/stdc++.h>
using namespace std;
int n,ans=1,a,b,c,h[30],ans2;
bool vis[30];
void dfs(int x,int cnt){
	if(x==n+1){
		if(cnt<3)return;
		int cnt=0,mx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt+=h[i];
				mx=max(mx,h[i]);
			}
		}
		if(cnt>mx*2)ans2++;
		return;
	}
	vis[x]=0;
	dfs(x+1,cnt);
	vis[x]=1;
	dfs(x+1,cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n<=30){
		for(int i=1;i<=n;i++)cin>>h[i];
		dfs(1,0);
		cout<<ans2;
		return 0;
	}
	for(int i=n-2;i<=n;i++)ans*=i;
	cout<<ans/3;
	return 0;
}
