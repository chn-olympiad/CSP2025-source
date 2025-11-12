#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ull B=13331;
ll n,m,ans,a[200005],sz;
string s[200005],t[200005],l,r;
ull pw[5000005],hs[200005],ht[200005],hl[5000005],hr;
ll gethl(ll l,ll r){
	return hl[r]-hl[l-1]*pw[r-l+1];
}
bool rep(ll l,ll r,ll k){
	return (gethl(l,r)==hs[k])&&((hl[sz]+(ht[k]-gethl(l,r))*pw[l-1])==hr);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*B;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		a[i]=s[i].size();
		s[i]=' '+s[i];
		t[i]=' '+t[i];
		for(int j=1;j<=a[i];j++) hs[i]=hs[i]*B+s[i][j];
		for(int j=1;j<=a[i];j++) ht[i]=ht[i]*B+t[i][j];
	}
	while(m--){
		cin>>l>>r;
		sz=l.size();
		l=' '+l;
		r=' '+r;
		ans=hr=0;
		for(int i=1;i<=sz;i++) hl[i]=hl[i-1]*B+l[i];
		for(int i=1;i<=sz;i++) hr=hr*B+r[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j+a[i]-1<=sz;j++){
				ans+=rep(j,j+a[i]-1,i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
