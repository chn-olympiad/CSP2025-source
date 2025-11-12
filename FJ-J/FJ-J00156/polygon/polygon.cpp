#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=998224353;

//bool cmp(int x,int y){
//	return x>y;
//}

//int query(int l,int r){
//	return sum[r]^sum[l-1];
//}
int n,a[maxn],sum[maxn],ans,vis[maxn];

bool check(){
	int cnt=0,maxx=-1,t=0;
	for(int i=1;i<=n;++i){
		if(vis[i]){
			t++;
			maxx=max(maxx,a[i]);
			cnt+=a[i];
		}
	}
	if(t<3) return false;
	return cnt>2*maxx;
}

void dfs(int x){
	if(x>n) return;
	
	vis[x]=1;
	ans=(ans+check())%mod;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	
	sort(a+1,a+1+n);
	
	dfs(1);
	
	cout<<ans<<'\n';
	return 0;
}
