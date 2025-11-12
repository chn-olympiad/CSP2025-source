#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 2e5 + 5;

int n,q;
struct node{
	string a,b;
}g[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> g[i].a >> g[i].b;
	}
	while(q--){
		string s,t;
		int ans = 0;
		cin >> s >> t;
		int len = s.length();
		for(int i = 0; i < len; i++){
			for(int j = 1;j <= n; j++){
				if(s[i] == g[j].a[0]){
					bool can = 1;
					for(int k = 1; k < g[j].a.length();k++){
						if(s[i + k] != g[j].a[k]){
							can = 0;break;
						}
					}
					if(can){
						string ss = s;
						for(int k = 0; k < g[j].a.length();k++){
							ss[i + k] = g[j].b[k];
						}
						if(ss == t) ans++;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
4 3
xabcx
xadex
ab cd
bc de
aa bb
xabcx xadex
aa bb
aaaa bbbb
*/
