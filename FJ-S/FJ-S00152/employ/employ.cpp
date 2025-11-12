#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int mod=998244353;
using pii=pair<int,int>;
int n,m;
string s;
int a[510];
int st[510];
vector<pii>v;
int ans=0;
int dp[100010];
void dfs(int cnt){
	if(cnt==n+1){
		int sum=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				if(v[i].second>=i) sum++;
			}
		}
		if(sum>=m) ans++;
		ans%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			cnt++;
			v.push_back({i,a[i]});
			dfs(cnt);
			cnt--;
			st[i]=0;
			v.pop_back();
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1); 	
	cout<<ans%mod;
	return 0;
} 
