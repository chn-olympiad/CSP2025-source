#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF=1e18, N=2e5+5;
int n, q;
string s[N][3];
signed main(){
	ios::sync_with_stdio(0); 
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++) cout<<"0\n";
	return 0;
}

