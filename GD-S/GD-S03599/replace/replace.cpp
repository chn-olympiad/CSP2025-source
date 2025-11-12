#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+5,M=2e5+5;
int tot,trie[N][26],f[N],c[N],len[N];
ll ans[M],tree[N];
vector<int>e[N];
vector<pair<int,int>>g[N];
void insert(string s){
	int p=0;
	for(int i=0;i<int(s.size());i++){
		int h=(s[i]-'a');
		if(!trie[p][h]){
			trie[p][h]=++tot;
			len[tot]=len[p]+1;
		}
		p=trie[p][h];
	}
	c[p]++;
}
void bfs(){
	queue<int>q;
	for(int i=0;i<26;i++){
		if(trie[0][i]){
			q.push(trie[0][i]);
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(trie[x][i]){
				f[trie[x][i]]=trie[f[x]][i];
				q.push(trie[x][i]);
			}else{
				trie[x][i]=trie[f[x]][i];
			}
		}
	}
}
void ask(string s,int l,int r,int id){
	int p=0;
	for(int i=0;i<int(s.size());i++){
		int h=s[i]-'a';
		if(!trie[p][h])return ;
		p=trie[p][h];
		if(i<r||i%2==0)continue;
		g[p].push_back(make_pair(i-l+1,id));
	}
}
int lowbit(int x){
	return x&(-x);
}
void add(int x,ll y){
	for(int i=x;i<N;i+=lowbit(i)){
		tree[i]+=y;
	}
}
ll query(int x){
	ll res=0;
	for(int i=x;i>=1;i-=lowbit(i)){
		res+=tree[i];
	}
	return res;
}
void dfs(int x){
	if(len[x]&&c[x]){
		add(len[x],c[x]);
	}
	for(int i=0;i<int(g[x].size());i++){
		int id=g[x][i].second,l=g[x][i].first;
		ans[id]+=query(len[x])-query(l-1);
	}
	for(int y:e[x]){
		dfs(y);
	}
	if(len[x]&&c[x]){
		add(len[x],-c[x]);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2,h;
		cin>>s1>>s2;
		for(int j=0;j<int(s1.size());j++){
			h.push_back(s1[j]);
			h.push_back(s2[j]);
		}
		insert(h);
	}
	bfs();
	for(int i=1;i<=tot;i++){
		e[f[i]].push_back(i);
	}
	for(int id=1;id<=q;id++){
		string t1,t2,h;
		int r=0,l=-1;
		cin>>t1>>t2;
		for(int i=0;i<int(t1.size());i++){
			h.push_back(t1[i]);
			h.push_back(t2[i]);
			if(t1[i]!=t2[i]){
				r=h.size()-1;
				if(l==-1){
					l=h.size()-2;
				}
			}
		}
		ask(h,l,r,id);
	}
	dfs(0);
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
