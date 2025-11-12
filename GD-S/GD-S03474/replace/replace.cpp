#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=5000005,base=1125,mod=998244353,base2=3435,mod2=1000000007;
int n,q;
string s[N],S[N],t,T;
unordered_map<unsigned int,unsigned int>mp;
inline unsigned int h(string &s){
	unsigned int r=0,R=0;
	for(auto i:s)r=(r*base%mod+i)%mod;
	for(auto i:s)R=(R*base2%mod2+i)%mod2;
	return (r<<32)|R;
}
signed main(){
#ifndef XYZ
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>S[i],mp[h(s[i])]=h(S[i]);
	while(q--){
		cin>>t>>T;
		int r=0;
		int lcp=0,lcs=0;
		for(int i=0;i<t.size();i++){
			if(t[i]==T[i])++lcp;
			else break;
		}
		for(int i=t.size()-1;i>=0;i--){
			if(t[i]==T[i])++lcs;
			else break;
		}
		for(int i=0;i<t.size();i++){
			unsigned int z=0,Z=0,zz=0,ZZ=0;
			if(i>lcp)continue;
			for(int j=i;j<t.size();j++){
				z=(z*base%mod+t[j])%mod;
				Z=(Z*base2%mod2+t[j])%mod2;
				zz=(zz*base%mod+T[j])%mod;
				ZZ=(ZZ*base2%mod2+T[j])%mod2;
				if(j+lcs>=t.size()-1&&mp.count(z<<32|Z)&&mp[z<<32|Z]==(zz<<32|ZZ))++r;
			}
		}
		cout<<r<<'\n';
	}
	return 0;
}


