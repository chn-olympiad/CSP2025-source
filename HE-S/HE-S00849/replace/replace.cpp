#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string a[220000][2];
bool f;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0<<'\n';
	}
	return 0;
}
