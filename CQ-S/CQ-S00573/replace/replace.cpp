#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int maxn=2e6+10,base=1000,mod=998244353;
cc_hash_table<int,cc_hash_table<int,cc_hash_table<int,int>>>G;
int gh(string s){
	int h=0;
	for(char ch:s)h=(h*base+ch)%mod;
	return h;
}
int pw[maxn],hs[maxn],ht[maxn];
int qh(int h[],int l,int r){
	if(l>r)return 0;
	return (h[r]-h[l-1]*pw[r-l+1]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	pw[0]=1;for(int i=1;i<=2e6;i++)pw[i]=pw[i-1]*base%mod;
	int m,q;cin>>m>>q;
	while(m--){
		string s,t;cin>>s>>t;
		G[s.size()][gh(s)][gh(t)]++;
	}
	while(q--){
		string s,t;cin>>s>>t;
		if(s.size()!=t.size())cout<<0<<'\n';
		else{
			int n=s.size();
			s=' '+s;t=' '+t;
			for(int i=1;i<=n;i++){
				hs[i]=(hs[i-1]*base+s[i])%mod;
				ht[i]=(ht[i-1]*base+t[i])%mod;
			}
			int ans=0;
			for(auto &[len,mp]:G){
				for(int l=1,r=len;r<=n;l++,r++){
					if(qh(hs,1,l-1)==qh(ht,1,l-1)&&qh(hs,r+1,n)==qh(ht,r+1,n)){
						int hhs=qh(hs,l,r),hht=qh(ht,l,r);
						if(mp.find(qh(hs,l,r))!=mp.end()){
							if(mp[hhs].find(hht)!=mp[hhs].end()){
								ans+=mp[hhs][hht];
							}
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
//$O(n+q+L1\sqrt{L2})$, best wishes.
