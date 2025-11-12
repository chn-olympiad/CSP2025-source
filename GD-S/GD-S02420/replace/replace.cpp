bool mem_st;
#include<bits/stdc++.h>
using namespace std;
#define MAXN 5000005
int n,q;
string s[200005][3],t[200005][3];
int ans[200005];
typedef unsigned long long ull;
struct h{
	ull ha,hb;
	h():ha(0),hb(0){}
	void add(char c){
		ha=(ha*1145141ull+(unsigned int)c)%998244353u;
		hb=(hb*1919811ull+(unsigned int)c)%1000000007u;
	}
	inline ull val()const{
		return ha<<32u|hb;
	}
};
vector<pair<ull,pair<int,int> > >a;
struct node{
	vector<ull>vals;
	vector<int>ids;
	int nxt[26];
}tr[MAXN];
unordered_map<ull,int>mp;
void work(int id){
//	cerr<<"eval:"<<id<<'\n';
	int r=(int)t[id][1].size()-1;
	while(t[id][1][r]==t[id][2][r])--r;
	h res;
	if(mp.count(0))ans[id]+=mp[0];
	for(int i=r+1;i<(int)t[id][1].size();++i){
		res.add(t[id][1][i]);
		ull tmp=res.val();
		if(mp.count(tmp))ans[id]+=mp[tmp];
	}
}
void dfs(int rt){
	sort(tr[rt].vals.begin(),tr[rt].vals.end());
	for(auto it:tr[rt].vals)++mp[it];
	for(auto id:tr[rt].ids)work(id);
	for(int j=0;j<26;++j)if(tr[rt].nxt[j])dfs(tr[rt].nxt[j]);
	for(auto it:tr[rt].vals)--mp[it];
}
int rt=0,cnt=0;
void ins(int&rt,string&s,int idx,ull v){
	if(!rt){
		rt=++cnt;
		tr[rt].vals.clear();
		tr[rt].ids.clear();
		memset(tr[rt].nxt,0,sizeof(tr[rt].nxt));
	}
	if(idx==-1){
		tr[rt].vals.emplace_back(v);
		return;
	}
	else{
		ins(tr[rt].nxt[s[idx]-'a'],s,idx-1,v);
	}
}
void insq(int rt,string&s,int idx,int id){
	while(rt){
		if(idx==-1){
			tr[rt].ids.emplace_back(id);
			return;
		}
		int trt=tr[rt].nxt[s[idx]-'a'];
		if(!trt){
			tr[rt].ids.emplace_back(id);
			return;
		}
		rt=trt;
		--idx;
	}
}
bool mem_ed;
signed main(){
//	cerr<<(&mem_st-&mem_ed)/1048576.0<<'\n';
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	a.reserve(n+q);
	string s1,s2;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		if(s1==s2)continue;
		s[i][1]=s1,s[i][2]=s2;
		h res;
		int l=0,r=(int)s1.size()-1;
		while(s1[l]==s2[l])++l;
		while(s1[r]==s2[r])--r;
		for(int i=l;i<=r;++i){
			res.add(s1[i]),res.add(s2[i]);
		}
		a.emplace_back(make_pair(res.val(),make_pair(i,0)));
	}
	sort(a.begin(),a.end());
	for(int i=1;i<=q;++i){
		cin>>s1>>s2;
		t[i][1]=s1,t[i][2]=s2;
		h res;
		int l=0,r=(int)s1.size()-1;
		while(s1[l]==s2[l])++l;
		while(s1[r]==s2[r])--r;
		for(int i=l;i<=r;++i){
			res.add(s1[i]),res.add(s2[i]);
		}
		a.emplace_back(make_pair(res.val(),make_pair(i,1)));
	}
	sort(a.begin(),a.end());
	for(int l=0,r;l<(int)a.size();l=r+1){
		r=l;
		while(r+1<(int)a.size()&&a[r+1].first==a[l].first)++r;
		int c[2]={0,0};
		for(int i=l;i<=r;++i){
			++c[a[i].second.second];
		}
		if(!c[0]||!c[1])continue;
//		cerr<<"working:"<<l<<' '<<r<<'\n';
		rt=0;
		cnt=0;
		for(int i=l;i<=r;++i)if(!a[i].second.second){
			int id=a[i].second.first;
			int l=0,r=(int)s[id][1].size()-1;
			while(s[id][1][l]==s[id][2][l])++l;
			while(s[id][1][r]==s[id][2][r])--r;
			h res;
			for(int j=r+1;j<(int)s[id][1].size();++j){
				res.add(s[id][1][j]);
			}
//			cerr<<"ins: "<<s[id][1].substr(0,l)<<' '<<res.val()<<'\n';
			ins(rt,s[id][1],l-1,res.val());
		}
		for(int i=l;i<=r;++i)if(a[i].second.second){
			int id=a[i].second.first;
			int l=0;
			while(t[id][1][l]==t[id][2][l])++l;
			insq(rt,t[id][1],l-1,id);
		}
		dfs(rt);
	}
	for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
}
