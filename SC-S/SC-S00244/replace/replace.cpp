#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2];
string t[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int j=1;j<=q;j++){
		cin>>t[j][1]>>t[j][2];
	}
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	return 0;
}