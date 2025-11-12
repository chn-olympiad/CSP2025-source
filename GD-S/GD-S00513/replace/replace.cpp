#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=2e5+3,Alph=29,mod=998244353+114514;
int n,q;
string s[maxn][2],t[maxn][2];
pair<int,int> s1[maxn],s2[maxn],t1[maxn],t2[maxn],t0[maxn];
map<pair<int,int>,vector<pair<int,int> > > mp;
void solveB(){
	for(register int i=1; i<=n; i++){
		int siz=s[i][0].size();
		for(register int j=0; j<siz; j++)
		if(s[i][0][j]=='b'){
			s1[i]={j,siz-j-1};
			break;
		}
		for(register int j=0; j<siz; j++)
		if(s[i][1][j]=='b'){
			s2[i]={j,siz-j-1};
			break;
		}
		mp[make_pair(s1[i].first-s2[i].first,s1[i].second-s2[i].second)].push_back(s1[i]);
	}
	for(register int i=1; i<=q; i++){
		int siz=t[i][0].size();
		for(register int j=0; j<siz; j++)
		if(t[i][0][j]=='b'){
			t1[i]={j,siz-j-1};
			break;
		}
		for(register int j=0; j<siz; j++)
		if(t[i][1][j]=='b'){
			t2[i]={j,siz-j-1};
			break;
		}
		t0[i]={t1[i].first-t2[i].first,t1[i].second-t2[i].second};
	}
	for(register int i=1; i<=q; i++){
		int ans=0;
		for(pair<int,int> j:mp[t0[i]]){
			if(j.first<=t1[i].first&&j.second<=t1[i].second) ans++;
		}
		cout << ans << '\n';
	}
}
ll hs[maxn][2],ht[maxn][2];
inline ll ksm(ll x,int pw){
	ll res=1;
	while(pw){
		if(pw&1) res=x*res%mod;
		x=x*x%mod;
		pw>>=1;
	}
	return res;
}
void solve25(){
	ll calc;
	for(register int i=1; i<=q; i++){
		int ans=0;
		for(register int j=1; j<=n; j++){
			for(register int k=0; k+s[j][0].size()<t[i][0].size(); k++){
				calc=ht[i][0]+ksm(ll(Alph),k)*((hs[j][1]-hs[j][0]+mod)%mod)%mod;
				if(calc==ht[i][1]) {ans++;break;} 
			}
		}
		cout << ans << '\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	int len=0;
	for(register int i=1; i<=n; i++){
		cin >> s[i][0] >> s[i][1];
		len+=s[i][0].size();
		for(register int j=0; j<s[i][0].size(); j++){
			hs[i][0]=(hs[i][0]*Alph%mod+s[i][0][j]-'a'+1)%mod;
			hs[i][1]=(hs[i][1]*Alph%mod+s[i][1][j]-'a'+1)%mod;
		}
	}
	for(register int i=1; i<=q; i++){
		cin >> t[i][0] >> t[i][1];
		len+=s[i][0].size();
		for(register int j=0; j<t[i][0].size(); j++){
			ht[i][0]=(ht[i][0]*Alph%mod+t[i][0][j]-'a'+1)%mod;
			ht[i][1]=(ht[i][1]*Alph%mod+t[i][1][j]-'a'+1)%mod;
		}
	}
	if(len<8848) solve25();
	else solveB();
	return 0;
} 
