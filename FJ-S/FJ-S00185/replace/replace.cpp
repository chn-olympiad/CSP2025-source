#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int M=1e6+10;

int n,m,u,v,rcnt,dep,head[N],ans;
string ss,tt,s1,s2;

int cnt,dcnt;
struct node{
	int son[26];
	int fail;
	bool exist;
}trie[M],drie[M];

struct edge{
	int to;
	int next;
	int w;
}r[N];

void add(int u,int v,int w){
	r[++rcnt].to=v;
	r[rcnt].next=head[u];
	r[rcnt].w=w;
	head[u]=rcnt;
}

int insert(string s){
	int id=0,c;
	dep=0;
	for(int i=0;i<s.size();i++){
		c=s[i]-'a';
		if(!trie[id].son[c]){
			trie[id].son[c]=++cnt;
		}
		id=trie[id].son[c];
	}
	trie[id].exist=true;
	return id;
}

int insertD(string s){
	int id=0,c;
	for(int i=0;i<s.size();i++){
		c=s[i]-'a';
		if(!drie[id].son[c]){
			drie[id].son[c]=++dcnt;
		}
		id=drie[id].son[c];
	}
	return id;
}

queue<int> q;

void getfail(){
	for(int i=0;i<26;i++){
		if(trie[0].son[i])q.push(trie[0].son[i]);
	}
	int u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();
//		cout<<u<<'\n';
		for(int i=0;i<26;i++){
			v=trie[u].son[i];
			if(!v){
				trie[u].son[i]=trie[trie[u].fail].son[i];
				continue;
			}
			trie[v].fail=trie[trie[u].fail].son[i];
			q.push(v);
		}
	}
}

void getfailD(){
	for(int i=0;i<26;i++){
		if(drie[0].son[i])q.push(drie[0].son[i]);
	}
	int u,v;
	while(!q.empty()){
		u=q.front();
		q.pop();
//		cout<<u<<'\n';
		for(int i=0;i<26;i++){
			v=drie[u].son[i];
			if(!v){
				drie[u].son[i]=drie[drie[u].fail].son[i];
				continue;
			}
			drie[v].fail=drie[drie[u].fail].son[i];
			q.push(v);
		}
	}
}

void print(){
	for(int i=0;i<=cnt;i++){
		cout<<i<<"<fail> "<<trie[i].fail<<'\n';
		for(int j=0;j<26;j++){
			if(!trie[i].son[j])continue;
			cout<<i<<"--"<<char(j+'a')<<"->"<<trie[i].son[j]<<'\n';
		}
	}
}

void printD(){
	for(int i=0;i<=dcnt;i++){
		cout<<i<<"<fail> "<<drie[i].fail<<'\n';
		for(int j=0;j<26;j++){
			if(!drie[i].son[j])continue;
			cout<<i<<"--"<<char(j+'a')<<"->"<<drie[i].son[j]<<'\n';
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ss>>tt;
		u=insert(ss);
		v=insertD(tt);
		add(u,v,dep);
	}
//	print();
	getfail();
	getfailD();
//	print();
//	printD();
	int nail,id,did,iid;
	while(m--){
		cin>>s1>>s2;
		ans=0;
		int beg=0,end=0;
		for(int i=1;i<=s1.size();i++){
			if(s1[i-1]!=s2[i-1]){
				if(!beg)end=beg=i;
				else end=i;
			}
		}
		nail=1,id=0,did=0;
		for(;nail<=end;nail++){
			id=trie[id].son[s1[nail-1]-'a'];
			did=drie[did].son[s2[nail-1]-'a'];
		}
		for(;nail<=s1.size();nail++){
			iid=id;
			if(trie[iid].exist){
				while(iid){
					for(int i=head[iid];i;i=r[i].next){
						if(nail-r[i].w<beg)ans++;
					}
					iid=trie[iid].fail;
				}
			}
			id=trie[id].son[s1[nail-1]-'a'];
			did=drie[did].son[s2[nail-1]-'a'];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
