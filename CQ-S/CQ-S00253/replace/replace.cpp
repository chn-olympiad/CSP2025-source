#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define fr first
#define sc second
#define pq priority_queue
#define gr greater
#define mkp make_pair
using ll=long long;
using db=double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int N=5e6+5,mod1=19260817,p1=229,mod2=1e9+9,p2=131;
int n,q,a[N];
pll h1[N],h2[N],H1[N],H2[N];
ll pw1[N],pw2[N];

pll Hash1(int l,int r){
	pll res;
	res.fr=(H1[r].fr-H1[l-1].fr*pw1[r-l+1]%mod1+mod1)%mod1;
	res.sc=(H1[r].sc-H1[l-1].sc*pw2[r-l+1]%mod2+mod2)%mod2;
	return res;
}

pll Hash2(int l,int r){
	pll res;
	res.fr=(H2[r].fr-H2[l-1].fr*pw1[r-l+1]%mod1+mod1)%mod1;
	res.sc=(H2[r].sc-H2[l-1].sc*pw2[r-l+1]%mod2+mod2)%mod2;
	return res;
}

pll gethash(string &str){
	pll res={0,0};
	for(auto ch:str){
		res.fr=(res.fr*p1%mod1+ch-'a')%mod1;
		res.sc=(res.sc*p2%mod2+ch-'a')%mod2;
	}
	return res;
}

void solve(){
	pw1[0]=pw2[0]=1;
	for(int i=1;i<N;i++){
		pw1[i]=pw1[i-1]*p1%mod1;
		pw2[i]=pw2[i-1]*p2%mod2;
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		a[i]=s.size(),h1[i]=gethash(s),h2[i]=gethash(t);
	}
	
	while(q--){
		int m;
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		m=s.size(),s=' '+s,t=' '+t;
		for(int i=1;i<=m;i++){
			H1[i].fr=(H1[i-1].fr*p1%mod1+s[i]-'a')%mod1;
			H1[i].sc=(H1[i-1].sc*p2%mod2+s[i]-'a')%mod2;
			H2[i].fr=(H2[i-1].fr*p1%mod1+t[i]-'a')%mod1;
			H2[i].sc=(H2[i-1].sc*p2%mod2+t[i]-'a')%mod2;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j+a[i]-1<=m;j++){
				if(h1[i]!=Hash1(j,j+a[i]-1)) continue;
				if(h2[i]!=Hash2(j,j+a[i]-1)) continue;
				if(j>1&&H1[j-1]!=H2[j-1]) continue;
				if(j+a[i]<=m&&Hash1(j+a[i],m)!=Hash2(j+a[i],m)) continue;
				pll tmp1=Hash1(j+a[i],m),tmp2=Hash2(j+a[i],m);
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
//	cin>>T;
    while(T--) solve();
    return 0;
}
