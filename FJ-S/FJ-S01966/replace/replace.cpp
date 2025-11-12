#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
ll n,q;
string s[N][3],t[N][3];
ll ans[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(ll i=1; i<=n; i++)
		cin>>s[i][1]>>s[i][2];
	for(ll i=1; i<=q; i++)
		cin>>t[i][1]>>t[i][2];
	for(ll i=1; i<=q; i++) {
		for(ll j=1; j<=n; j++) {
			for(ll k=s[j][1].size()-1; k<t[i][1].size(); k++) {
				ll u=k,v=s[j][1].size()-1;
				while(s[j][1][v]==t[i][1][u]) u--,v--;
				if(v<0) {
					string g;
					for(ll p=0; p<=u; p++)
						g=g+t[i][1][p];
					g+=s[j][2];
					for(ll p=k+1; p<t[i][1].size(); p++)
						g=g+t[i][1][p];
					if(g==t[i][2])
						ans[i]++;
				}
			}
		}
	}
	for(ll i=1; i<=q; i++)
		cout<<ans[i]<<endl;
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