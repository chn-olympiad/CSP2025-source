#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
using namespace std;
const int N = 1e5+10;
const int M = 5e6+10;
const ull P = 1331;
int n,m,Q; 
int len[N];
string s[N][2];
vector<ull> pre[N][2];
ull pw[M];
ull gethsh(int x,int y,int l,int r){
	return pre[x][y][r]-pre[x][y][l-1]*pw[r-l+1];
}
unordered_map<ull,int> mp;
vector<vector<int>> v;
string t[2];
vector<ull> sum[2];
ull geth(int x,int l,int r){
	if(l > r) return 0;
	return sum[x][r]-sum[x][l-1]*pw[r-l+1];
}
bool chk(int x,int i){
	if(len[x]+i-1 > m) return false;
	int r = i+len[x]-1;
	if(geth(0,i,r) != pre[x][0][len[x]]) return false;
	if(sum[0][i-1]*pw[m-i+1]+pre[x][1][len[x]]*pw[m-r]+geth(0,r+1,m) == sum[1][m]) return true;
	return false;
}
void solve(){
	cin >> n >> Q;
	pw[0] = 1;
	for(int i=1;i<=5000000;i++) pw[i] = pw[i-1]*P;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
		len[i] = s[i][0].size();
		pre[i][0].resize(len[i]+1);
		pre[i][1].resize(len[i]+1);
		for(int j=0;j<=1;j++){
			for(int k=1;k<=len[i];k++){
				pre[i][j][k] = pre[i][j][k-1]*P+s[i][j][k-1];
			}
		}
		v.push_back({});
		for(int k=1;k<=len[i];k++){
			ull hh = pre[i][0][k]*pw[k]+pre[i][1][k];
			if(!mp[hh]) mp[hh] = ++cnt,v.push_back({});
			int now = mp[hh];
			v[now].push_back(i);
		}
	}
	while(Q--){
		cin >> t[0] >> t[1];
		if(t[0].size() != t[1].size()){
			cout << "0\n";
			continue;
		}
		m = t[0].size();
		sum[0].resize(m+1);
		sum[1].resize(m+1);
		for(int j=0;j<=1;j++) 
			for(int i=1;i<=m;i++){
				sum[j][i] = sum[j][i-1]*P+t[j][i-1];
			} 
		int mn = m,mx = 1;
		for(int i=0;i<m;i++){
			if(t[0][i] != t[1][i]){
				mn = min(mn,i+1);
				mx = max(mx,i+1);
			}
		}
		int ans = 0;
//		cout << mn << " " << mx << "\n";
		for(int i=mn;i>=1;i--){
			ull h1 = geth(0,i,mx)*pw[mx-i+1]+geth(1,i,mx);
			if(mp.count(h1)){
				
				int id = mp[h1];
//				cout << i <<" " << h1 <<" " << id <<"\n";
				for(int x : v[id]){
//					cout << x << "\n";
					ans += chk(x,i);
				}
			}
		}
		cout << ans << "\n";
	}
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int T = 1;
	while(T--) solve(); 
	return 0;
}
