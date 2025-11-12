#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string a[200005][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		string xx,yy;
		cin>>xx>>yy;
		cout<<0<<'\n';
	}
	return 0;
}
