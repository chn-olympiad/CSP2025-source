#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int buf[1<<10];
inline void print(int x,char ch=' '){
	if(x<0) putchar('-'),x=-x;
	int tot=0;
	do{
		buf[++tot]=x%10;
		x/=10;
	}while(x);
	for(int i=tot;i;i--)
		putchar(buf[i]+'0');
	putchar(ch);
}
const int N=2e5+5,M=5e6+5;
bool Mbe;
int n,q;
char s[M],t[M];

#define ull unsigned long long
const ull base=1145141;
int tot,num;
struct node{
	int x,y,id;
	ull key;
}a[N],b[N];
int ans[N];

int t1[M][26],tot1,t2[M][26],tot2;
int siz1[M],dfn1[M];
int siz2[M],dfn2[M];
void dfs1(int x){
	siz1[x]=1;
	dfn1[x]=++tot1;
	for(int i=0;i<26;i++){
		if(t1[x][i]){
			dfs1(t1[x][i]);
			siz1[x]+=siz1[t1[x][i]];
		}
	}		
}
void dfs2(int x){
	siz2[x]=1;
	dfn2[x]=++tot2;
	for(int i=0;i<26;i++){
		if(t2[x][i]){
			dfs2(t2[x][i]);
			siz2[x]+=siz2[t2[x][i]];
		}
	}
}

node func(int m){
	node ans;

	int L=0,R=0;
	for(int j=1;j<=m;j++){
		if(s[j]!=t[j]){
			if(!L) L=j;
			R=j;
		}
	}
	
	int rot=0;
	for(int j=L-1;j>=1;j--){
		int c=s[j]-'a';
		if(!t1[rot][c]) t1[rot][c]=++tot1;
		rot=t1[rot][c];
	}
	ans.x=rot;
	
	rot=0;
	for(int j=R+1;j<=m;j++){
		int c=s[j]-'a';
		if(!t2[rot][c]) t2[rot][c]=++tot2;
		rot=t2[rot][c];
	}
	ans.y=rot;

	ans.key=0;
	for(int j=L;j<=R;j++)
		ans.key=ans.key*base+s[j];
	for(int j=L;j<=R;j++)
		ans.key=ans.key*base+t[j];
	return ans;
}

ull temp[N<<1];
struct NODE{
	int x,y,z;
	int id;
	NODE(int a=0,int b=0,int c=0,int d=0){
		x=a;
		y=b;
		z=c;
		id=d;
	}
	bool friend operator<(const NODE &a,const NODE &b){
		return a.x<b.x;
	}
};
struct fenwick{
	#define lowbit(x) (x&(-x))
	int t[M];
	void update(int l,int r,int w){
		for(int i=l;i<M;i+=lowbit(i)) t[i]+=w;
		for(int i=r+1;i<M;i+=lowbit(i)) t[i]-=w;
	}
	int query(int x){
		int ans=0;
		for(int i=x;i;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
	void clear(int x){
		for(int i=x;i<M;i+=lowbit(i)){
			if(!t[i]) return ;
			t[i]=0;
		}
	}
}tr;
vector<NODE> qa[N<<1],qb[N<<1];
void solve(int id){
	sort(qa[id].begin(),qa[id].end());
	sort(qb[id].begin(),qb[id].end());
	int pos=0;
	for(auto x:qb[id]){
		while(pos<qa[id].size()&&qa[id][pos].x<=x.x){
			tr.update(qa[id][pos].y,qa[id][pos].z,qa[id][pos].id);
			pos++;
		}
		ans[x.id]=tr.query(x.y);
	}
	for(auto x:qa[id]){
		tr.clear(x.y);
		tr.clear(x.z+1);
	}
}
void solve(){
	int cnt=0;
	for(int i=1;i<=tot;i++) temp[++cnt]=a[i].key;
	for(int i=1;i<=num;i++) temp[++cnt]=b[i].key;
	sort(temp+1,temp+cnt+1);
	for(int i=1;i<=tot;i++){
		a[i].key=lower_bound(temp+1,temp+cnt+1,a[i].key)-temp;
		int l=dfn2[a[i].y],r=dfn2[a[i].y]+siz2[a[i].y]-1;
		qa[a[i].key].push_back(NODE(dfn1[a[i].x],l,r,1));
		qa[a[i].key].push_back(NODE(dfn1[a[i].x]+siz1[a[i].x],l,r,-1));
	}
	for(int i=1;i<=num;i++){
		b[i].key=lower_bound(temp+1,temp+cnt+1,b[i].key)-temp;
		qb[b[i].key].push_back(NODE(dfn1[b[i].x],dfn2[b[i].y],0,b[i].id));
	}

	for(int i=1;i<=cnt;i++) solve(i);
}
bool Med;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,t+1);

		int m=strlen(s+1),flag=1;
		for(int j=1;j<=m;j++)
			if(s[j]!=t[j]) flag=0;
		if(flag) continue;

		a[++tot]=func(m);		
	}

	for(int i=1;i<=q;i++){
		scanf("%s%s",s+1,t+1);
		int m=strlen(s+1),k=strlen(t+1);
		if(m!=k) continue;

		b[++num]=func(m);
		b[num].id=i;
	}

	tot1=0;
	dfs1(0);
	tot2=0;
	dfs2(0);

	solve();

	for(int i=1;i<=q;i++) print(ans[i],'\n');
	return 0;
}