#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2.5e6+5,M=2e5+5;
int n,q,rt1,rt2,tot1,tot2,a[M],b[M],tt1,tt2,fi1[N],fi2[N],id[N],tot,sz[N],fa[25][N];
ll ans[M],tr[N*4];
string s1,s2;
vector<pair<int,int>>v[N],cl[N];
vector<int>ins[N];
struct nd{int to,la;}e1[N],e2[N];
struct node{int s[26],fail,sz;}t1[N],t2[N];
int trip1(int &x,int y){
	if(x==0&&y!=0)x=++tot1;
	t1[x].sz=y;
	if(y==s1.size()-1)return x;
	return trip1(t1[x].s[s1[y+1]-'a'],y+1);
}
int trip2(int &x,int y){
	if(x==0&&y!=0)x=++tot2;
	t2[x].sz=y;
	if(y==s2.size()-1)return x;
	return trip2(t2[x].s[s2[y+1]-'a'],y+1);
}
void add1(int x,int y){e1[++tt1]={y,fi1[x]},fi1[x]=tt1;}
void add2(int x,int y){e2[++tt2]={y,fi2[x]},fi2[x]=tt2;}
void bt1(){
	queue<int>q;
	for(int i=0;i<26;i++){
		if(t1[rt1].s[i]!=0)q.push(t1[rt1].s[i]);
	}
	while(q.size()!=0){
		int x=q.front();
		add1(t1[x].fail,x);
		q.pop();
		for(int i=0;i<26;i++){
			if(t1[x].s[i]!=0){
				q.push(t1[x].s[i]);
				t1[t1[x].s[i]].fail=t1[t1[x].fail].s[i];
			}
			else t1[x].s[i]=t1[t1[x].fail].s[i];
		}
	}
}
void bt2(){
	queue<int>q;
	for(int i=0;i<26;i++){
		if(t2[rt2].s[i]!=0)q.push(t2[rt2].s[i]);
	}
	while(q.size()!=0){
		int x=q.front();
		add2(t2[x].fail,x);
		q.pop();
		for(int i=0;i<26;i++){
			if(t2[x].s[i]!=0){
				q.push(t2[x].s[i]);
				t2[t2[x].s[i]].fail=t2[t2[x].fail].s[i];
			}
			else t2[x].s[i]=t2[t2[x].fail].s[i];
		}
	}
}
void dfs1(int x){
	for(int i=1;i<=23;i++)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(int i=fi1[x];i;i=e1[i].la){
		fa[0][e1[i].to]=x;
		dfs1(e1[i].to);
	}
}
void dfs2(int x){
	sz[x]=1,id[x]=++tot;
	for(int i=fi2[x];i;i=e2[i].la){
		dfs2(e2[i].to);
		sz[x]+=sz[e2[i].to];
	}
}
void upt(int x,int l,int r,int ql,int qr,ll opt){
	if(ql<=l&&qr>=r){
		tr[x]+=opt;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)upt(x*2,l,mid,ql,qr,opt);
	if(qr>mid)upt(x*2+1,mid+1,r,ql,qr,opt);
}
ll qry(int x,int l,int r,int w){
	if(l==r)return tr[x];
	int mid=(l+r)>>1;
	if(w<=mid)return tr[x]+qry(x*2,l,mid,w);
	return tr[x]+qry(x*2+1,mid+1,r,w);
}
void dfs3(int x){
	for(int i:ins[x])upt(1,1,tot2,id[i],id[i]+sz[i]-1,1);
	for(auto i:v[x])ans[i.second]+=qry(1,1,tot2,id[i.first]);
	for(auto i:cl[x])ans[i.second]-=qry(1,1,tot2,id[i.first]);
	for(int i=fi1[x];i;i=e1[i].la)dfs3(e1[i].to);
	for(int i:ins[x])upt(1,1,tot2,id[i],id[i]+sz[i]-1,-1);
}
int gt(int x,int y){
	for(int i=23;i>=0;i--){
		if(t1[fa[i][x]].sz>=y)x=fa[i][x];
	}
	return fa[0][x];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2,s1='-'+s1,s2='-'+s2;
		a[i]=trip1(rt1,0),b[i]=trip2(rt2,0);
		ins[a[i]].push_back(b[i]);
	}
	bt1();bt2();
	dfs1(rt1);
	dfs2(rt2);
	for(int i=1;i<=q;i++){
		cin>>s1>>s2,s1='-'+s1,s2='-'+s2;
		if(s1.size()!=s2.size())continue;
		int l=0,r=s1.size(),w1=rt1,w2=rt2;
		for(int j=1;j<s1.size();j++){
			if(s1[j]==s2[j])l=j;
			else break;
		}
		for(int j=s1.size()-1;j;j--){
			if(s1[j]==s2[j])r=j;
			else break;
		}
		for(int j=1;j<s1.size();j++){
			w1=t1[w1].s[s1[j]-'a'];
			w2=t2[w2].s[s2[j]-'a'];
			if(j>=r-1&&t1[w1].sz>=max(0,j-l)){
				int op=gt(w1,max(0,j-l));
				v[w1].push_back({w2,i});
				cl[op].push_back({w2,i});
			}
		}
	}
	dfs3(rt1);
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
