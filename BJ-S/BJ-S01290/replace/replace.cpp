#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,q;
string s1[N],s2[N];
string t1,t2;
vector<ll> kmp1[N];

int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(ll j=0;j<=s1[i].size();j++){
			kmp1[i].push_back(0);
		}

		ll j=0;
		for(ll k=2;k<s1[i].size();k++){
			while(j&&s1[i][k]!=s1[i][j+1]){
				j=kmp1[i][j];
			}
			if(s1[i][k]==s1[i][j+1])j++;
			kmp1[i][k]=j;
		}
	}
	while(q--){
//		cout<<q<<endl;
		ll ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(ll i=1;i<=n;i++){
			if(s1[i].size()>t1.size()) continue;

			ll j=0;
			for(ll k=1;k<t1.size();k++){
				while(j&&s1[i][j+1]!=t1[k]){
					j=kmp1[i][j];
				}
				if(s1[i][j+1]==t1[k])j++;
				if(j>=s1[i].size()-1){
//					cout<<i<<" "<<k<<endl;
					ll l=k-s1[i].size()+1;
					ll r=k;
//					cout<<l<<" "<<r<<endl;
					string x,z;
					if(l>=1) x=t1.substr(0,l);
					if(r<t1.size()) z=t1.substr(r+1,t1.size());
					string y=x+s2[i]+z;
//					cout<<y<<endl;
					if(y==t2){
						ans++;
					}
					j=kmp1[i][j];
				}
			}
		}
		cout<<ans<<endl;
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