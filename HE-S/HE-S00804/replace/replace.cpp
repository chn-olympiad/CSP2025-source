#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
const int N=2e5+10,M=6e6+10;
int n,m;
char s1[M],s2[M];
int L[N],V[N];
int b[M],a[M],c[M];
int cntn;
ull base='c'+'t'+'r'+'m'+'y'+'m'+'q';
ull h[N];
int tot;
int rt[M],ch[M][27],ed[M],f[M],fa[M];
queue<int>q;
map<int,map<ull,int> >mp;

void Insert(int v,int len){
	if(!rt[v]) rt[v]=++tot;
	int p=rt[v];
	for(int i=1;i<=len;i++){
		if(!ch[p][c[i]]) ch[p][c[i]]=++tot;
		p=ch[p][c[i]];
	}
	ed[p]++; f[p]++;
}

void Init(int v){
	if(!rt[v]) return ;
	int p=rt[v];
	fa[p]=p;
	for(int i=0;i<=26;i++){
		if(ch[p][i]){
			q.push(ch[p][i]);
			fa[ch[p][i]]=p;
		}
		else ch[p][i]=p;
	}
	while(!q.empty()){
		int u=q.front(); q.pop();
		int F=fa[u];
		for(int i=0;i<=26;i++){
			int x=ch[u][i];
			if(!x) ch[u][i]=ch[F][i];
			else {
				fa[x]=ch[F][i];
				f[x]=ed[x]+f[fa[x]];
				q.push(x);
			}
		}
	}
}

void Solve(){
	scanf("%s",s1+1); scanf("%s",s2+1);
	int len=strlen(s1+1);
	int q1=0,q2=0;
	for(int j=1;j<=len;j++){
		if(s1[j]==s2[j]) a[j]=s1[j]-'a';
		else {
			if(!q1) q1=j; q2=j;
			a[j]=(s1[j]-'a'+1)*26+(s2[j]-'a');
		}
	}
	int val;
	if(q2) val=q2-q1+1;
	else val=0;
	ull H=0;
	if(q2){
		for(int j=q1;j<=q2;j++) H=H*base+a[j];	
	}
	if(!mp[val][H]){
		printf("0\n");
		return ;
	}
	int ans=0;
	int num=0;
	if(!q2){
		for(int j=1;j<=len;j++) c[++num]=s1[j]-'a';
	}
	else {
		for(int j=1;j<q1;j++) c[++num]=s1[j]-'a';
		c[++num]=26;
		for(int j=q2+1;j<=len;j++) c[++num]=s1[j]-'a';
	}
	int v=mp[val][H];
	int p=rt[v];
	for(int i=1;i<=num;i++){
		p=ch[p][c[i]];
		ans+=f[p];
	}
	printf("%d\n",ans);
}

int main(){
	//system("fc 1.out 2.out");
	//return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s1+1); scanf("%s",s2+1);
		int len=strlen(s1+1);
		int q1=0,q2=0;
		for(int j=1;j<=len;j++){
			if(s1[j]==s2[j]) a[j]=s1[j]-'a';
			else {
				if(!q1) q1=j; q2=j;
				a[j]=(s1[j]-'a'+1)*26+(s2[j]-'a');
			}
		}
		if(q2) V[i]=q2-q1+1;
		else V[i]=0;
		if(q2){
			for(int j=q1;j<=q2;j++) h[i]=h[i]*base+a[j];	
		}
		if(!mp[V[i]][h[i]]) mp[V[i]][h[i]]=++cntn;
		int num=0;
		if(!q2){
			for(int j=1;j<=len;j++) c[++num]=s1[j]-'a';
		}
		else {
			for(int j=1;j<q1;j++) c[++num]=s1[j]-'a';
			c[++num]=26;
			for(int j=q2+1;j<=len;j++) c[++num]=s1[j]-'a';
		}
		Insert(mp[V[i]][h[i]],num);
	}
	for(int i=1;i<=cntn;i++) Init(i);
	for(int i=1;i<=m;i++) Solve();
	return 0;
}
