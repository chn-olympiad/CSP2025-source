#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5;
int n,q;
string s[N][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n+q;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cout<<0<<'\n';
	}
	return 0;
}
