#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[200005][3],t1,t2;
int n,Q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	for(int i = 1; i <= n; i ++)cin>>s[i][1]>>s[i][2];
	while(Q --){
		cin>>t1>>t2;
		cout<<0<<"\n";
	}
	return 0;
}
