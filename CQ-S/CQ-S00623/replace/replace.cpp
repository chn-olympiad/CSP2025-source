#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2e5+5;
const int N = 5e6+5;
const ll p=13331;
const ll mod = 998244353;
int n,q;
ll g[N],a[N],pq=1e9+7;
string s1[M],s2[M],t1,t2;
struct node{
	ll pr,mida,midb,sf;
}s[M],t[M];
map<pair<ll,ll>,int>mp;
unordered_map<ll,bool>ump;
int cnt;
int lsh(ll x,ll y){
	if(!mp[{x,y}])mp[{x,y}]=++cnt;
	return mp[{x,y}];
}
vector<ll>ve[M];
void ycl(){
	g[0]=1;
	for(int i=1;i<N;i++)g[i]=g[i-1]*p%mod;
}
ll query(ll l,ll r){
	return (a[r]-a[l-1]*g[r-l+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	ycl();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i])continue;
		int len=s1[i].size(),l=0,r=0;
		for(l=1;s1[i][l-1]==s2[i][l-1];l++);
		for(r=len;s1[i][r-1]==s2[i][r-1];r--);
		l--,r++;
		for(int j=1;j<=len;j++){
			a[j]=(a[j-1]*p%mod+s1[i][j-1]-'a'+5)%mod;
		}
		s[i].pr=query(1,l),s[i].mida=query(l+1,r-1);
		for(int j=1;j<=len;j++){
			a[j]=(a[j-1]*p%mod+s2[i][j-1]-'a'+5)%mod;
		}
		s[i].midb=query(l+1,r-1),s[i].sf=query(r,len);
		ve[lsh(s[i].pr,(s[i].mida*g[r-l-1]%mod+s[i].midb)%mod)].push_back(s[i].sf);
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len=t1.size(),l=0,r=0;
		for(l=1;t1[l-1]==t2[l-1];l++);
		for(r=len;t1[r-1]==t2[r-1];r--);
		l--,r++;
		for(int j=1;j<=len;j++){
			a[j]=(a[j-1]*p%mod+t1[j-1]-'a'+5)%mod;
		}
		t[i].pr=query(1,l),t[i].mida=query(l+1,r-1);
		for(int j=1;j<=len;j++){
			a[j]=(a[j-1]*p%mod+t2[j-1]-'a'+5)%mod;
		}
		t[i].midb=query(l+1,r-1),t[i].sf=query(r,len);
		ll o=(t[i].mida*g[r-l-1]%mod+t[i].midb)%mod;
		for(int j=r-1;j<=len;j++){
			ll gf=query(r,j);
			ump[gf]=1;
		}
		int ans=0;
		for(int j=l+1;j>0;j--){
			ll w=query(j,l);
			if(!mp.count({w,o}))continue;
			int u=mp[{w,o}];
			for(ll v:ve[u])if(ump[v]){
				ans++;
			}
		}
		cout<<ans<<"\n";
		ump.clear();
	}
}
