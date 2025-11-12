#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+2,M=5e6+2;
int Q1,Q2,ans[N],tot,cnt,rt1[N],rt2[N],nx[M][26],fa[M],c[M];
vector<int>g[M];
vector<pair<int,int>>q[M]; 
string s1,s2,t1,t2;
unordered_map<ull,int>mp;
void dfs(int u){
	for(int v:g[u])++c[v];
	for(auto i:q[u])
		for(int v=i.first;v;v=fa[v])ans[i.second]+=c[v];
	for(int i=0;i<26;i++)if(nx[u][i])dfs(nx[u][i]);
	for(int v:g[u])--c[v];
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>Q1>>Q2;
	while(Q1--){
		cin>>s1>>s2;
		if(s1==s2)continue;
		int sz=s1.size(),p1=0,p2=sz-1;
		while(s1[p1]==s2[p1])++p1;
		while(s1[p2]==s2[p2])--p2;
		ull H=0;
		for(int i=p1;i<=p2;i++)H=29*(29*H+s1[i]-'a')+s2[i]-'a';
		if(!mp.count(H))mp[H]=++tot,rt1[tot]=++cnt,rt2[tot]=++cnt;
		t1=t2="";
		for(int i=p1-1;~i;i--)t1+=s1[i];
		for(int i=p2+1;i<sz;i++)t2+=s1[i];
		int u=rt1[mp[H]],v=rt2[mp[H]];
		for(auto i:t1){
			i-='a';
			if(!nx[u][i])fa[nx[u][i]=++cnt]=u;
			u=nx[u][i];
		}
		for(auto i:t2){
			i-='a';
			if(!nx[v][i])fa[nx[v][i]=++cnt]=v;
			v=nx[v][i];
		}
		g[u].push_back(v);
	}
	for(int i=1;i<=Q2;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size())continue;
		int sz=s1.size(),p1=0,p2=sz-1;
		while(s1[p1]==s2[p1])++p1;
		while(s1[p2]==s2[p2])--p2;
		ull H=0;
		for(int i=p1;i<=p2;i++)H=29*(29*H+s1[i]-'a')+s2[i]-'a';
		if(!mp.count(H))continue;
		t1=t2="";
		for(int i=p1-1;~i;i--)t1+=s1[i];
		for(int i=p2+1;i<sz;i++)t2+=s1[i];
		int u=rt1[mp[H]],v=rt2[mp[H]];
		for(auto i:t1){
			i-='a';
			if(!nx[u][i])break;
			u=nx[u][i];
		}
		for(auto i:t2){
			i-='a';
			if(!nx[v][i])break;
			v=nx[v][i];
		}
		q[u].push_back({v,i});
	}
	for(int i=1;i<=tot;i++)dfs(rt1[i]);
	for(int i=1;i<=Q2;i++)cout<<ans[i]<<'\n';
}
