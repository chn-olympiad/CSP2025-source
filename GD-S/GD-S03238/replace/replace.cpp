#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=2e5+5,M=1e6+5;
int n,q,l,ll,x,y,p;
string s1[N],s2[N],t1,t2;
void solve(){
	cin>>t1>>t2;
	ll=t1.size();
	p=0;
	for(rint i=0;i<ll;++i) if(t1[i]!=t2[i]){x=i;break;}
	for(rint i=ll-1;i>=0;--i) if(t1[i]!=t2[i]){y=i;break;}
	for(rint o=1;o<=n;++o){
		l=s1[o].size();
		for(rint i=0;i<=ll-l;++i){
			if(i>x||y>i+l-1) continue;
			bool t=1;
			for(rint j=0;j<l;++j){
				if(s1[o][j]!=t1[i+j]||s2[o][j]!=t2[i+j]){t=0;break;}
			}
			if(t){
				++p;
				break;
			}
		}
	}
	cout<<p<<'\n';
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(rint i=1;i<=n;++i) cin>>s1[i]>>s2[i];
	while(q--) solve();
	return 0;
}
