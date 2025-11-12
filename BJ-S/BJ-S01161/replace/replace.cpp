#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
ll l[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].size();
	}
	while(q--){
		string s,S;
		cin>>s>>S;
		ll len=s.size();
		s=" "+s;
		ll ans=0;
		for(ll i=1;i<=len;i++){
			for(ll j=1;j<=n;j++){
				if(s.substr(i,l[j])==s1[j]){
					//cout<<i<<" "<<j<<" ";
					string t=s.substr(1,i-1)+s2[j]+s.substr(i+l[j],n-(i+l[j])+2);
					//cout<<t<<"\n";
					if(t==S){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}