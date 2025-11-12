#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e6;
ll n,Q,sd[N][2];
string s[N+10],s2[N+10],st,sty,buto[N+10],tb[N+10];
map<string,ll>mp;
vector<pair<ll,ll>> v;
bool hjl[N+10];
ll dfs(ll p,ll len,bool test[1005]){
	if(p>len) return 1;
	string h="",h2="";
	ll last=sd[p][0],sum=0;
	for(int i=p;i<=len;i++){
		h+=st[i],h2+=sty[i];
		last=sd[i][1]+1;
		ll tp=mp[h];
		if((tp>0&&s2[tp]==h2&&test[tp]!=1)||(h==h2)){
			test[tp]=1;
			sum+=dfs(i+1,len,test);
		}
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
		ll pasf=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]!=s2[i][j]||pasf==1){
				buto[i]+=s[i][j];
				tb[i]+=s2[i][j];
				pasf=1;
			}
		}
	}
	if(n<=1000&&Q<=1000){
		for(int i=1;i<=n;i++){
			mp[s[i]]=i;
		}
		while(Q--){
			cin>>st>>sty;
			ll last=-1,len=0;
			cout<<dfs(0,st.size()-1,hjl)<<"\n";
		}
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
