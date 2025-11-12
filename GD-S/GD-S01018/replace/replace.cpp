#include<bits/stdc++.h>
#define ull unsigned long long
#define pll pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e6+8;
const int bas1=1331,mod1=1e9+7,
		  bas2=1949,mod2=1e9+9;
int pw1[N],pw2[N];
void prework(int n){
	pw1[0]=1;
	for(int i=1;i<=n;i++) pw1[i]=1ll*pw1[i-1]*bas1%mod1;
	pw2[0]=1;
	for(int i=1;i<=n;i++) pw2[i]=1ll*pw2[i-1]*bas2%mod2;
}
int n,q;
string s1,s2;
map<pair<pll,pll>,int> mp;
pll h1[N],h2[N];
inline pll gethsh1(int l,int r){
	if(l>r) return {0,0};
	pll tmp;
	tmp.fi=(h1[r].fi-1ll*h1[l-1].fi*pw1[r-l+1]%mod1+mod1)%mod1;
	tmp.se=(h1[r].se-1ll*h1[l-1].se*pw2[r-l+1]%mod2+mod2)%mod2;
	return tmp;
}
inline pll gethsh2(int l,int r){
	if(l>r) return {0,0};
	pll tmp;
	tmp.fi=(h2[r].fi-1ll*h2[l-1].fi*pw1[r-l+1]%mod1+mod1)%mod1;
	tmp.se=(h2[r].se-1ll*h2[l-1].se*pw2[r-l+1]%mod2+mod2)%mod2;
	return tmp;
} 
bitset<N> vis;
vector<int> len;
void work(){
	cin>>n>>q;
	for(int p=1;p<=n;p++){
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size();
		vis[l1]=1;
		int hsh1=0,hsh2=0;
		for(int i=0;i<l1;i++){
			hsh1=(1ll*hsh1*bas1+s1[i]-'a')%mod1;
			hsh2=(1ll*hsh2*bas2+s1[i]-'a')%mod2;
		}
		pll h1={hsh1,hsh2};
		hsh1=0,hsh2=0;
		for(int i=0;i<l2;i++){
			hsh1=(1ll*hsh1*bas1+s2[i]-'a')%mod1;
			hsh2=(1ll*hsh2*bas2+s2[i]-'a')%mod2;
		}
		pll h2={hsh1,hsh2};
		mp[{h1,h2}]++;
	}
	for(int i=1;i<N;i++) if(vis[i]) len.push_back(i);
	while(q--){
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size();
		s1="#"+s1;
		s2="#"+s2;
		for(int i=1;i<=l1;i++){
			h1[i].fi=(1ll*h1[i-1].fi*bas1+s1[i]-'a')%mod1;
			h1[i].se=(1ll*h1[i-1].se*bas2+s1[i]-'a')%mod2;
		}
		for(int i=1;i<=l2;i++){
			h2[i].fi=(1ll*h2[i-1].fi*bas1+s2[i]-'a')%mod1;
			h2[i].se=(1ll*h2[i-1].se*bas2+s2[i]-'a')%mod2;
		}
		int ans=0;
		for(int l:len){
			if(l>l1) break;
			for(int i=l;i<=l1;i++){
				if(l1-i+1>=l2) continue;
				pll t1,t2;
				t1=gethsh1(1,i-l);
				t2=gethsh2(1,i-l);
				if(!(t1==t2)) break;
				t1=gethsh1(i+1,l1);
				t2=gethsh2(l2-l1+i+1,l2);
				//cout<<i<<" "<<t1.fi<<" "<<t2.fi<<"\n";
				if(!(t1==t2)) continue;
				t1=gethsh1(i-l+1,i);
				t2=gethsh2(i-l+1,l2-(l1-i));
				//cout<<t1.fi<<" "<<t2.fi<<"\n";
				if(mp.count({t1,t2})){
					ans+=mp[{t1,t2}];
					//cout<<mp[{t1,t2}]<<"\n";
				}
			} 
		}
		cout<<ans<<"\n";
	}
}
int main(){
	prework(N-8);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int T=1;//cin>>T;
	while(T--){
		work();
	}
	return 0;
}
/*

*/
