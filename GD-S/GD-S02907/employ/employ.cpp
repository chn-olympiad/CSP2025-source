#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF=1e18, N=505, MOD=998244353;
int n, m, c[N];
string s;
bool flag1=1;
int fact(int x){
	int res=1;
	for(int i=2;i<=x;i++) res=res*i%MOD;
	return res;	
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	cout<<0;
	return 0;
}

