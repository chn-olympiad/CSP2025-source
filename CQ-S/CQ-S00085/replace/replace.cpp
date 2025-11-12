#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll d[4]={97,87,83,73},mod[4]={998244353,998244853,1000000007,202031887};
ll n,q;
string s[200001][2],t[2];
ll l[200001],r[200001];
vector<ll>gr[200001][4];
vector<ll>gs[4];
ll g(char x,char y) {
	return (x-'a')*26+(y-'a')+1;
}
ll qpow(ll x,ll y,ll module) {
//	cout<<x<<' '<<y<<' '<<module;
	ll res=1;
	while(y) {
		if(y&1)
			res=res*x%module;
		x=x*x%module;
		y>>=1;
	}
	return res;
}
ll sace(ll x,ll y) {
	return (x%mod[y]+mod[y])%mod[y];
}
pair<pair<ll,ll>,pair<ll,ll>> cl1(ll i,ll x,ll y) {
//	cout<<x<<' '<<y<<'\n';
	if(y<x)
		return make_pair(make_pair(-1,-1),make_pair(-1,-1));
	return make_pair(make_pair(sace((gr[i][0][y]-gr[i][0][x-1]*qpow(d[0],(1ll)*(y-x+1),mod[0])%mod[0]),0),sace(gr[i][1][y]-gr[i][1][x-1]*qpow(d[1],(1ll)*(y-x+1),mod[1])%mod[1],1)),make_pair(sace(gr[i][2][y]-gr[i][2][x-1]*qpow(d[2],(1ll)*(y-x+1),mod[2])%mod[2],2),sace(gr[i][3][y]-gr[i][3][x-1]*qpow(d[3],(1ll)*(y-x+1),mod[3])%mod[3],3)));
}
pair<pair<ll,ll>,pair<ll,ll>> cl2(ll x,ll y) {
//	cout<<x<<' '<<y<<'\n';
	if(y<x)
		return make_pair(make_pair(-1,-1),make_pair(-1,-1));
	return make_pair(make_pair(sace((gs[0][y]-gs[0][x-1]*qpow(d[0],(y-x+1),mod[0])%mod[0]),0),sace(gs[1][y]-gs[1][x-1]*qpow(d[1],(1ll)*(y-x+1),mod[1])%mod[1],1)),make_pair(sace(gs[2][y]-gs[2][x-1]*qpow(d[2],(1ll)*(y-x+1),mod[2])%mod[2],2),sace(gs[3][y]-gs[3][x-1]*qpow(d[3],(1ll)*(y-x+1),mod[3])%mod[3],3)));
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n*q<=20000000) {
		for(int i=1;i<=n;i++) {
			cin>>s[i][0]>>s[i][1]; 
			s[i][0]=" "+s[i][0];  
			s[i][1]=" "+s[i][1]; 
			for(int k=0;k<4;k++)
				gr[i][k].push_back(0);
			for(int j=1;j<s[i][0].size();j++) {
				for(int k=0;k<4;k++)
					gr[i][k].push_back(gr[i][k][j-1]);
				gr[i][0][j]=(gr[i][0][j]*d[0]%mod[0]+g(s[i][0][j],s[i][1][j]))%mod[0];
				gr[i][1][j]=(gr[i][1][j]*d[1]%mod[1]+g(s[i][0][j],s[i][1][j]))%mod[1];
				gr[i][2][j]=(gr[i][2][j]*d[2]%mod[2]+g(s[i][0][j],s[i][1][j]))%mod[2];
				gr[i][3][j]=(gr[i][3][j]*d[3]%mod[3]+g(s[i][0][j],s[i][1][j]))%mod[3];
			}
			l[i]=LONG_LONG_MAX,r[i]=LONG_LONG_MIN;
			for(ll j=1;j<s[i][0].size();j++)
				if(s[i][0][j]!=s[i][1][j])
					l[i]=min(l[i],j),r[i]=max(r[i],j);
//			cout<<l[i]<<' '<<r[i]<<'\n';
		}
//		cout<<cl1(3,1,2).first.first<<'\n';
		for(int i=1;i<=q;i++) {
			cin>>t[0]>>t[1];
			t[0]=" "+t[0];  
			t[1]=" "+t[1]; 
			for(int k=0;k<4;k++)
				gs[k].clear(),gs[k].push_back(0);
			for(int j=1;j<t[0].size();j++) {
				for(int k=0;k<4;k++)
					gs[k].push_back(gs[k][j-1]);
				gs[0][j]=(gs[0][j]*d[0]%mod[0]+g(t[0][j],t[1][j]))%mod[0];
				gs[1][j]=(gs[1][j]*d[1]%mod[1]+g(t[0][j],t[1][j]))%mod[1];
				gs[2][j]=(gs[2][j]*d[2]%mod[2]+g(t[0][j],t[1][j]))%mod[2];
				gs[3][j]=(gs[3][j]*d[3]%mod[3]+g(t[0][j],t[1][j]))%mod[3];
			}
			ll tl=LONG_LONG_MAX,tr=LONG_LONG_MIN;
			for(ll j=1;j<t[0].size();j++)
				if(t[0][j]!=t[1][j])
					tl=min(tl,j),tr=max(tr,j);
//			cout<<gs[0][4]-gs[0][2]*qpow(d[0],2,mod[0]);
//			cout<<cl2(tl,tr).first.first<<'\n';
			ll ans=0;
			for(int j=1;j<=n;j++) {
//				cout<<(cl1(j,l[j],r[j])==cl2(tl,tr))<<"\n";
				if(tr-tl==r[j]-l[j]&&l[j]<=tl&&s[j][0].size()-r[j]<=t[0].size()-tr&&cl1(j,1,l[j]-1)==cl2(tl-l[j]+1,tl-1)&&cl1(j,l[j],r[j])==cl2(tl,tr)&&cl1(j,r[j]+1,s[j][0].size()-1)==cl2(tr+1,tr-r[j]+s[j][0].size()-1))
					ans++;
			}
			cout<<ans<<'\n';
		}
	}
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
