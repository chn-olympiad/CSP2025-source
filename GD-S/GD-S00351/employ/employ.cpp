#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e2;
const ll mod=998244353;
ll n,m,c[N+10],p[N+10],u[N+10];
string s;
vector<ll>v;
ll qow(ll x){
	ll sum=1;
	for(int i=1;i<=x;i++){
		sum=(sum*i)%mod;
	}return sum;
}
ll dfs(vector<ll> tv,ll j,ll lq,ll zuo,ll shan){
	if(lq>=m) return qow(tv.size());
	ll cnt=tv.size();
	if(min(u[n]-u[j-1],cnt)+lq<m||tv.size()==0) return 0;
	vector<ll> pv;
	for(auto i:tv){
		if(c[i]<zuo) zuo++; 
		else if(i!=shan)pv.push_back(i);
	} 
	if(p[j]==0) zuo++;
	else lq++;
	ll d,sum=0;
	for(auto i:pv){
		sum+=dfs(pv,j+1,lq,zuo,i);
	}return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		v.push_back(i);
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') p[i+1]=1;
		u[i+1]=p[i+1]+u[i];
	}cout<<1;
	cout<<dfs(v,1,0,0,-1)<<"\n";
	return 0;
}/*
3 2
101
1 1 2
*/
