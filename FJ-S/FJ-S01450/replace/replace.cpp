#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
ll n,q;set<pair<string,string>> sp; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		string st1,st2;cin>>st1>>st2;
		sp.insert(mkp(st1,st2));
	}
	for(ll i=1;i<=q;i++){
		string s,t;cin>>s>>t;ll rp=s.size();
		if(s.size()!=t.size()){
			cout<<0<<endl;
		}else{
			s=" "+s,t=" "+t;ll ans=0;
			for(ll i=1;i<=rp;i++){
				for(ll j=i;j<=rp;j++){
					string rt1,rt2,lt,rt;
					for(ll k=i;k<=j;k++) rt1+=s[k];
					for(ll k=i;k<=j;k++) rt2+=t[k];
//					cout<<rt1<<" "<<rt2<<" "<<s1.count(rt1)<<" "<<s2.count(rt2)<<endl;
					for(ll k=1;k<i;k++) lt+=s[k];
					for(ll k=j+1;k<=rp;k++) rt+=s[k];
//					cout<<lt+rt2+rt<<endl;
					if((" "+lt+rt2+rt)==t&&(sp.count(mkp(rt1,rt2)))) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

