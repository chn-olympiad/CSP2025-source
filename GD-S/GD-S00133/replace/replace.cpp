#include <iostream>
#include <algorithm>
#include <vector>
#define PII pair<int,int>

using namespace std;

const int N=2e5+5,T=1e7+5;

int n,q,ls[N],rs[N],lt[N],rt[N],ans[N];
int tr[T][26],idx;
int dfn[T],cnt,c[T],sz[T];
string s[N][2],t[N][2];
struct E{
	int p1,p2,id;
}o[2*N];
vector<int> mdy[T];
vector<PII> qry[T];

void add(int p,int v){
	for (int i=p;i<=cnt;i+=i&-i) c[i]+=v;
}

int sum(int p){
	int v=0;
	for (int i=p;i;i-=i&-i) v+=c[i];
	return v;
}

void reset(){
	for (int i=0;i<=idx;i++){
		for (int j=0;j<26;j++)
			tr[i][j]=0;
		mdy[i].clear(),qry[i].clear();
	}
	idx=cnt=0;
}

int insert(string s){
	int p=0;
	for (auto c:s){
		c-='a';
		if (!tr[p][c]) tr[p][c]=++idx;
		p=tr[p][c];
	}
	return p;
}

void dfs(int u){
	dfn[u]=++cnt,sz[u]=1;
	for (int i=0;i<26;i++)
		if (tr[u][i])
			dfs(tr[u][i]),sz[u]+=sz[tr[u][i]];
}

void cal(int u){
	for (auto p:mdy[u])
		add(dfn[p],1),add(dfn[p]+sz[p],-1);
	for (auto i:qry[u])
		ans[i.second]=sum(dfn[i.first]);
	for (int i=0;i<26;i++)
		if (tr[u][i])
			cal(tr[u][i]);
	for (auto p:mdy[u])
		add(dfn[p],-1),add(dfn[p]+sz[p],1);
}

void work(int l,int r){
	int c0=0,c1=0;
	for (int i=l;i<=r;i++)
		(o[i].id<=n?c0:c1)++;
	if (!c0||!c1)
		return;
	reset();
	for (int i=l;i<=r;i++)
		if (o[i].id<=n){
			int id=o[i].id;
			string pre=s[id][0].substr(0,ls[id]),suf=s[id][0].substr(rs[id]+1);
			reverse(pre.begin(),pre.end());
			int id1=insert(pre),id2=insert(suf);
			mdy[id1].push_back(id2);
		}
		else{
			int id=o[i].id-n;
			string pre=t[id][0].substr(0,lt[id]),suf=t[id][0].substr(rt[id]+1);
			reverse(pre.begin(),pre.end());
			int id1=insert(pre),id2=insert(suf);
			qry[id1].push_back({id2,id});
		}
	dfs(0);
	for (int i=1;i<=cnt;i++) c[i]=0;
	cal(0);
}

int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	int tcnt=0;
	for (int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		if (s[i][0]==s[i][1]) continue;
		int L=0,R=s[i][0].size()-1;
		while (s[i][0][L]==s[i][1][L]) L++;
		while (s[i][0][R]==s[i][1][R]) R--;
		ls[i]=L,rs[i]=R;
		o[++tcnt]={insert(s[i][0].substr(L,R-L+1)),insert(s[i][1].substr(L,R-L+1)),i};
	}
	for (int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		if (t[i][0].size()!=t[i][1].size()) continue;
		int L=0,R=t[i][0].size()-1;
		while (t[i][0][L]==t[i][1][L]) L++;
		while (t[i][0][R]==t[i][1][R]) R--;
		lt[i]=L,rt[i]=R;
		o[++tcnt]={insert(t[i][0].substr(L,R-L+1)),insert(t[i][1].substr(L,R-L+1)),n+i};
	}
	sort(o+1,o+tcnt+1,[](E x,E y){return x.p1^y.p1?x.p1<y.p1:x.p2<y.p2;});
	for (int l=1,r=1;r<=tcnt;r++)
		if (r==tcnt||o[r].p1^o[r+1].p1||o[r].p2^o[r+1].p2)
			work(l,r),l=r+1;
	for (int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
	return cout<<flush,0;
} 

