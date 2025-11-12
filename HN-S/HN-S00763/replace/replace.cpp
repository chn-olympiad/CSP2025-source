#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+10;
ll n,m;
string a[N],b[N],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(m--){
		cin>>c>>d;
		string st=c;
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				ll t=c.find(a[j]);
				if(t!=-1){
					for(ll l=t;l<t+a[i].size();l++)c[l]=b[i][l-t];
					if(c==d){
						ans++;
						break;
					}
				}
			}
			c=st;
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

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
