#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn];
int vis[5];
int n,ans,cnt;
int cntb,cntc;
void dfs(int x,int js){
	if(x==n+1){
		ans=max(ans,js);
	}
	if(vis[1]<cnt){
		vis[1]++; 
		dfs(x+1,js+a[x]);
		vis[1]--;
	}
	if(vis[2]<cnt){
		vis[2]++;
		dfs(x+1,js+b[x]);
		vis[2]--;
	}
	if(vis[3]<cnt){
		vis[3]++;
		dfs(x+1,js+c[x]);
		vis[3]--;
	}
}
void solve(){
	cin>>n;
	cnt=n/2;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]==0) cntb++;
		if(c[i]==0) cntc++;
	}
	if(cntb==n && cntc==n){
		sort(a,a+1+n);
		for(int i=n;i>=n/2+1;--i){
			ans+=a[i];
		}
		cout<<ans<<endl;
		return ; 
	}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(vis,0,sizeof(vis));
		cntb=0;
		cntc=0;
		cnt=0;
		ans=0;
		solve();
	}
	return 0;
} 