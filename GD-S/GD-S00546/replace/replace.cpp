#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(x) ((x) -(x))

const int N = 3e5+5;
string x[N],y[N];
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>x[i]>>y[i];
	while(m--){
		string s,t;
		cin>>s>>t;
		if(s.size() != t.size()){
			cout<<"0\n";
			continue;
		}
		int ans = 0;
		for(int l = 0;l < s.size();l++){
			if(l){
				string ss = s.substr(0,l);
				string st = t.substr(0,l);
				if(ss != st) continue;
			}
			for(int i = 1;i <= n;i++){
				if(x[i].size() > s.size()) continue;
				string xx = s.substr(l,x[i].size());
				if(xx != x[i]) continue;
				string ns = s;
				ns.replace(l,y[i].size(),y[i]);
				ans+=(ns == t);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
