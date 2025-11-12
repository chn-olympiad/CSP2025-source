#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> PII;
// bool mst;
const int N=200005,L=5000005,P=29;
int n,m,tot,ans[N],tr[L][26],sz[L],et;
string s,t,ps[N],ss[N],pt[N],st[N];
vector<int> u[N],q[N];
map<PII,int> mp;
int insert(string s){
	int p=0;
	for(auto c:s){
		int to=c-'a';
		if(!tr[p][to])	tr[p][to]=++et;
		p=tr[p][to];
	}
	sz[p]++;return p;
}
int calc(string s){
	int p=0;int ans=sz[p];
	for(auto c:s){
		int to=c-'a';
		if(!tr[p][to])	return ans;
		ans+=sz[p=tr[p][to]];
	}
	return ans;
}
void solve(vector<int> u,vector<int> q,int op){
	if(u.empty()){for(auto p:q)ans[p]=calc(st[p]);return;}
	else if(q.empty())	return;
	vector<int> del;
	for(auto p:u){
		if(op)	ps[p].pop_back();
		if(ps[p].empty())	del.emplace_back(insert(ss[p]));
	}
	for(auto p:q){
		if(op)	pt[p].pop_back();
		if(pt[p].empty())	ans[p]=calc(st[p]);
	}
	vector<int> tu[26],tq[26];
	for(auto p:u)if(!ps[p].empty())
		tu[ps[p].back()-'a'].emplace_back(p);
	for(auto p:q)if(!pt[p].empty())
		tq[pt[p].back()-'a'].emplace_back(p);
	for(int i=0;i<26;i++)	solve(tu[i],tq[i],1);
	for(auto p:del)	sz[p]--;
}
// bool med;
int main(){
	// cerr<<fabs(&mst-&med)/1024.0/1024<<'\n';
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>t;int sz=s.size();
		int cp=0,cs=0;
		while(cp<sz&&s[cp]==t[cp])	cp++;
		while(cs<sz&&s[sz-cs-1]==t[sz-cs-1])	cs++;
		ps[i]=s.substr(0,cp),ss[i]=s.substr(sz-cs,cs);
		ull v1=0,v2=0;
		for(int i=cp;i+cs<sz;i++)
			v1=v1*P+s[i]-'a'+1,v2=v2*P+t[i]-'a'+1;
		int &res=mp[{v1,v2}];
		if(!res)	res=++tot;
		u[res].emplace_back(i);
	}
	for(int i=1;i<=m;i++){
		cin>>s>>t;if(s.size()!=t.size())continue;
		int sz=s.size(),cp=0,cs=0;
		while(cp<sz&&s[cp]==t[cp])	cp++;
		while(cs<sz&&s[sz-cs-1]==t[sz-cs-1])	cs++;
		pt[i]=s.substr(0,cp),st[i]=s.substr(sz-cs,cs);
		ull v1=0,v2=0;
		for(int i=cp;i+cs<sz;i++)
			v1=v1*P+s[i]-'a'+1,v2=v2*P+t[i]-'a'+1;
		int &res=mp[{v1,v2}];
		if(!res)	res=++tot;
		q[res].emplace_back(i);
	}
	s.clear(),t.clear(),s.shrink_to_fit(),t.shrink_to_fit();
	for(int i=1;i<=tot;i++){
		solve(u[i],q[i],0);
		u[i].clear(),u[i].shrink_to_fit();
		q[i].clear(),q[i].shrink_to_fit();
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<'\n';
	return 0;
}
