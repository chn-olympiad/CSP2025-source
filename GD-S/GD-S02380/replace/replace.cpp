#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e4+5,MAXM=2e5+5;
struct node{
	int son[26];
	int fail;
	int nxt[26];
	int op;
	int fa;
	bitset<MAXM> st;
};
int n,Q;
node t1[MAXN],t2[MAXN];
queue<int> q;
bitset<MAXM> now;
int cnt1=0,cnt2=0;
void build1(string x,int y){
	int now=0;
	for(int i=0;i<x.length();i++){
		if(!t1[now].nxt[x[i]-'a']){
			t1[now].nxt[x[i]-'a']=++cnt1;
		}
		t1[t1[now].nxt[x[i]-'a']].fa=now;
		now=t1[now].nxt[x[i]-'a']; 
		t1[now].op=x[i]-'a';
	}
	t1[now].st[y]=1;
}
void build2(string x,int y){
	int now=0;
	for(int i=0;i<x.length();i++){
		if(!t2[now].nxt[x[i]-'a']){
			t2[now].nxt[x[i]-'a']=++cnt2;
		}
		t2[t2[now].nxt[x[i]-'a']].fa=now;
		now=t2[now].nxt[x[i]-'a']; 
		t2[now].op=x[i]-'a';
	}
	t2[now].st[y]=1;
}
void bfs1(){
	q.push(0);
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		t1[tmp].fail=t1[t1[t1[tmp].fa].fail].son[t1[tmp].op];
		if(t1[tmp].fail==tmp){
			t1[tmp].fail=0;
		}
		t1[tmp].st|=t1[t1[tmp].fail].st;
		for(int i=0;i<26;i++){
			if(t1[tmp].nxt[i]){
				t1[tmp].son[i]=t1[tmp].nxt[i];
				q.push(t1[tmp].nxt[i]);
			}
			else{
				t1[tmp].son[i]=t1[t1[tmp].fail].son[i];
			}
		}
	}
}
void bfs2(){
	q.push(0);
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		t2[tmp].fail=t2[t2[t2[tmp].fa].fail].son[t2[tmp].op];
		if(t2[tmp].fail==tmp){
			t2[tmp].fail=0;
		}
		t2[tmp].st|=t2[t2[tmp].fail].st;
		for(int i=0;i<26;i++){
			if(t2[tmp].nxt[i]){
				t2[tmp].son[i]=t2[tmp].nxt[i];
				q.push(t2[tmp].nxt[i]);
			}
			else{
				t2[tmp].son[i]=t2[t2[tmp].fail].son[i];
			}
		}
	}
}
ll query(string x,string y){
	ll ans=0;
	int now1=0,now2=0;
	for(int i=0;i<x.length();i++){
		now1=t1[now1].son[x[i]-'a'];
		now2=t2[now2].son[y[i]-'a'];
		now=t1[now1].st&t2[now2].st;
		ans+=now.count();
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		build1(x,i);
		build2(y,i);
	}
	bfs1();
	bfs2();
	while(Q--){
		string x,y;
		cin>>x>>y;
		printf("%lld\n",query(x,y));
	}
}
