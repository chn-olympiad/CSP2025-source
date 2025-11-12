#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,q;
LL ans;
string inp1,inp2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>q;
	unordered_map<string,string> rep;
	for(int i=1;i<=n;i++){
		cin>>inp1>>inp2;
		rep[inp1] = inp2;
	}
	while(q--){
		ans = 0;
		cin>>inp1>>inp2;
		int len = inp1.size();
		for(auto m : rep){
			int lenm = m.first.size();
			for(int l=0;l+lenm-1<len;l++){
				if(inp1.substr(l,lenm)==m.first){
					string cur = inp1.substr(0,l) + m.second + inp1.substr(l+lenm,len-l-lenm);
					if(cur == inp2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
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
