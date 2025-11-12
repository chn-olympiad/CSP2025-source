#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXLEN=1000000,MAXN=200000;
ll n,Q,ot[MAXLEN+5][26],fail[MAXLEN+5],dep[MAXLEN+5],cnt;
pair<ll,ll> id[MAXN+5];
set<ll> st[MAXLEN+5];
ll Insert(string &s){
	ll now=0;
	for(ll i=0;i<s.size();i++){
		ll k=s[i]-'a';
		if(ot[now][k]==0){
			ot[now][k]=++cnt;
			dep[cnt]=dep[now]+1;
		}
		now=ot[now][k];
	}
	return now;
}
void get_fail(){
	queue<ll> q;
	for(ll i=0;i<26;i++) if(ot[0][i]) q.push(ot[0][i]);
	while(!q.empty()){
		ll h=q.front();q.pop();
		for(ll i=0;i<26;i++){
			if(ot[h][i]){
				fail[ot[h][i]]=ot[fail[h]][i];
				q.push(ot[h][i]);
			}
			else ot[h][i]=ot[fail[h]][i];
		}
	}
}
ll Query(ll x,ll y,ll mini){
	if(dep[x]<mini) return 0;
	ll num=0;
	auto ls=st[x].lower_bound(y);
	if(ls!=st[x].end()&&(*ls)==y) num=1;
	return num+Query(fail[x],fail[y],mini);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	for(ll i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		id[i].first=Insert(s1);
		id[i].second=Insert(s2);
		st[id[i].first].insert(id[i].second);
	}
	get_fail();
	for(ll i=1;i<=Q;i++){
		string s,t;cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		ll now1=0,now2=0,len=s.size(),ls=0;
		ll qz=0,hz=0,ans=0;
		while(s[qz]==t[qz]) qz++;
		while(s[len-hz-1]==t[len-hz-1]) hz++;
		ls=qz+hz;
		ll pos=len-hz;
		for(ll i=0;i<pos-1;i++){
			now1=ot[now1][s[i]-'a'];
			now2=ot[now2][t[i]-'a'];
		}
		for(ll i=pos-1;i<len;i++){
			now1=ot[now1][s[i]-'a'];
			now2=ot[now2][t[i]-'a'];
			ll n1=now1,n2=now2;
			while(dep[n1]>dep[n2]) n1=fail[n1];
			while(dep[n2]>dep[n1]) n2=fail[n2];
			ans+=Query(n1,n2,i-qz+1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
