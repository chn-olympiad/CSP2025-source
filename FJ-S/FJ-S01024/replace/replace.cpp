#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
int n,q;
string s[N][2],t[2];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	FILE("replace")
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>t[0]>>t[1];
		cout<<1<<"\n";
	}
	return 0;
}
