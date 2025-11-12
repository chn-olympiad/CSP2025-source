#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
const int INF=8.3E18, MAXN=5050;
using namespace std;
inline void io(string name=""){
	if(name.size()){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
int n, a[MAXN];
signed main(){
	io("polygon");
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cout<<((n*(n-1)>>1)-1)%MOD;
	return 0;
}
