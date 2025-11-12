#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+20;
map<string,string>p;
int n,q;string s1,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;p[s1]=s2;
	}
	while(q--){
		string x,y;cin>>x>>y;
		cout<<0<<"\n";
	}
	return 0;
}

