#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
//#define int long long

using namespace std;
const int N=1e5+10;
int T,n,a[N][3],vis[N];
ll ans;
void dfs(int cur,ll s){
	if(cur>n){
		ans=max(ans,s);
		return;
	}
	if(vis[1]+1<=n/2){
		vis[1]++;
		dfs(cur+1,s+a[cur][1]);
		vis[1]--;
	}
	if(vis[2]+1<=n/2){
		vis[2]++;
		dfs(cur+1,s+a[cur][2]);
		vis[2]--;
	}
	if(vis[3]+1<=n/2){
		vis[3]++;
		dfs(cur+1,s+a[cur][3]);
		vis[3]--;
	}
}
int w=0,b[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]==0&&a[i][3]==0)w++;
		}
		if(w==n){
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1,greater<int>());
			for(int i=1;i<=n/2;i++)ans+=b[i];
			cout<<ans<<endl;
			return 0;
		}
		dfs(1,0ll);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
