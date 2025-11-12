#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int n,m,ans[N],trie[N][26],tot,fail[N],siz[N],sign[N],vis[N];
unsigned long long p=13131,ksm[N];
char s[N],t[N],w1[N],w2[N];
queue<int>q;
vector<pair<int,int>>v[N];
vector<int>g[N];
struct node{
	unsigned long long s1,s2;
	int op,l,r,st,ed,id;
	inline bool operator<(node b){
		if(s1^b.s1)return s1<b.s1;
		if(s2^b.s2)return s2<b.s2;
		return op<b.op; 
	}
}a[N];
inline void insert(int l,int r,int x){
	int p = 0,ch;
	for(int i = l;i<=r;i++){
		ch=s[i]-'a';
		if(!trie[p][ch]){
			trie[p][ch]=++tot;
			for(int j = 0;j<26;j++)trie[tot][j]=0;
			fail[tot]=0;siz[tot]=0;sign[tot]=0;v[tot].clear();g[tot].clear();
		}
		p=trie[p][ch];
	}
	siz[p]++;sign[p]=x;
}
inline void dfs(int x){
	if(siz[x])vis[sign[x]]+=siz[x];
	for(auto t : v[x]){
		ans[t.second]+=vis[t.first];
	}
	for(int y : g[x])dfs(y);
	if(siz[x])vis[sign[x]]-=siz[x];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	ksm[0]=1;
	for(int i = 1;i<=5e6;i++)ksm[i]=ksm[i-1]*p;
	for(int i = 1;i<=n;i++){
		a[i].l=a[i-1].r+1;
		scanf("%s%s",w1+1,w2+1);int len = strlen(w1+1);
		a[i].r=a[i].l+len-1;a[i].op=0;
		unsigned long long x1=0,x2=0;
		for(int j = 1;j<=len;j++){
			s[a[i].l+j-1]=w1[j];
			if(w1[j]!=w2[j]){
				if(!a[i].st){
					a[i].st=j;
					x1=w1[j],x2=w2[j];
				}
				else x1+=w1[j]*ksm[j-a[i].st],x2+=w2[j]*ksm[j-a[i].st];
				a[i].ed=j;
			}
		}
		a[i].s1=x1,a[i].s2=x2;
	}
	for(int i = 1;i<=m;i++){
		a[i+n].l=a[i+n-1].r+1;
		if(i==1)a[i+n].l=1;
		scanf("%s%s",w1+1,w2+1);int len = strlen(w1+1);
		a[i+n].r=a[i+n].l+len-1,a[i+n].op=1;a[i+n].id=i;
		unsigned long long x1=0,x2=0;
		for(int j = 1;j<=len;j++){
			t[a[i+n].l+j-1]=w1[j];
			if(w1[j]!=w2[j]){
				if(!a[i+n].st){
					a[i+n].st=j;
					x1=w1[j],x2=w2[j];
				}
				else x1+=w1[j]*ksm[j-a[i+n].st],x2+=w2[j]*ksm[j-a[i+n].st];
				a[i+n].ed=j;
			}
		}
		a[i+n].s1=x1,a[i+n].s2=x2;
	}
	sort(a+1,a+n+m+1);
	for(int l = 1,r;l<=n+m;l=r+1){
		r=l;
		while(r<=n+m&&a[l].s1==a[r].s1&&a[l].s2==a[r].s2)r++;
		r--;
		if(a[l].op==1||a[r].op==0)continue;
		g[0].clear();v[0].clear();
		for(int i = 0;i<26;i++)trie[0][i]=0;
		tot=0;
		for(int i = l;i<=r;i++){
			if(a[i].op)break;
			insert(a[i].l,a[i].r,a[i].r-a[i].l+1 - a[i].ed);
		}
		for(int i = 0;i<26;i++)if(trie[0][i])q.push(trie[0][i]);
		while(q.size()){
			int x=q.front();q.pop();
			g[fail[x]].push_back(x);
			for(int i = 0;i<26;i++){
				if(trie[x][i])q.push(trie[x][i]),fail[trie[x][i]]=trie[fail[x]][i];
				else trie[x][i]=trie[fail[x]][i];
			}
		}
		for(int i = l;i<=r;i++){
			if(a[i].op){
				int p = 0;
				for(int j = a[i].l;j<=a[i].r;j++){
					p=trie[p][t[j]-'a'];
					if(j-a[i].l+1>=a[i].ed&&p){
						v[p].push_back({j-a[i].l+1-a[i].ed,a[i].id});
					}
				}
			}
		}
		dfs(0);
	}
	for(int i = 1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}


