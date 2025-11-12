/*
ygg plz!
luogu 1058570(the person who fought with kkksc03.)
plz 350+.

ok let this be t2 code.
seems O(2^k*n)?
oh t=1.
why m=1e6?
anyway next.

oh i think O(m log m+n*2^k).
m log m is for kruskal.

then,...

oh i solved it!!!!!!!!!!!!!!!!!!!!!!!!!

anyway the point i can get,
so baoli connect j with n+i-1!

then ...

oh is it O(m log m*n*2^k)?
...yes.LOL
this round is not easy at all.

i must think more.
O(2^k*m log m) can get 32.
then A:2^k is not necessary.this can get 24.

(16:22)i think it can be 100+56+50+24=230?
is it good or bad?
i hav less and less time.
it might be the best.
so i will try.
the solution might be difficult.
it's time to go.

i'll try to cut more ans to be faster.
if m=1e6 and k=5 be solved i'll got 72.
plz let sort faster!!!
try!!!

(16:47)why RE?
what did 3221225477 mean?
stack?
I USED --STACK!!!!!!!!!!!
WHY?
NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

ok v==n+1->v==k+1.LOL

so why WA?

i think kruskal.btw?

oh no kruskal is not correctttttttttttttttttttttttt???
it wasted time!!!noooooooooooooooooo
i hav 1h and 30min to get points.noo

this will get 16.idk how to keep it ok.
anyway NEXT.

(17:03)but can 10 edges cause 4e8?
might be other problems.
idk why!!!

why t2 is tulun?
my weakest..........
nooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

i know how to solve A.
it will be 48.
it is the last try!!!

why WA?

BRO WHY WA?
NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

(17:18)NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

(17:23)i find it!
it is 72!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
	{
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
	}//int x=read();
int n,m,k,us[15],anss=1e14+10299,a[15][10005],c[15],fa[10015],siz[10005];
struct node{int u,v,w;}e[1100005],e2[1100005];
int cmp(node x,node y){return x.w<y.w;}
int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
inline int merge(int x,int y)
	{
	if(siz[x]>siz[y])fa[y]=x,siz[x]+=siz[y];
	else fa[x]=y,siz[y]+=siz[x];
	return max(siz[x],siz[y]);
	}
inline void work(int ans)
	{
	for(int i=1;i<=n+k;i++)fa[i]=i,siz[i]=(i<=n);
	int m1=m;
	for(int i=1;i<=m;i++)e2[i].u=e[i].u,e2[i].v=e[i].v,e2[i].w=e[i].w;
	for(int i=1;i<=k;i++)
		{
		if(!us[i])continue;
		for(int j=1;j<=n;j++)
			{
			m1++;
			e2[m1].u=j,e2[m1].v=n+i,e2[m1].w=a[i][j];
			}
		}
	sort(e2+1,e2+m1+1,cmp);
	for(int i=1;i<=m1;i++)
		{
		int x=find(e2[i].u),y=find(e2[i].v);
		//cout<<e2[i].u<<' '<<x<<' '<<e2[i].v<<' '<<y<<' '<<e2[i].w<<'\n';
		if(x==y)continue;
		ans+=e2[i].w;if(anss<=ans)return;
		if(merge(x,y)==n){anss=min(anss,ans);return;}
		}
	//cerr<<114514<<'\n';
	}
void dfs(int v,int now)
	{
	if(now>anss)return;
	if(v==k+1){work(now);return;}
	us[v]=0;dfs(v+1,now);
	us[v]=1;dfs(v+1,now+c[v]);
	}
inline void sol()
	{
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)
		{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		}
	int lol=0;
	for(int i=1;i<=k;i++)
		{
		c[i]=read();lol+=c[i];
		for(int j=1;j<=n;j++)a[i][j]=read();
		}
	if(lol==0)
		{
		for(int i=1;i<=k;i++)us[i]=1;
		work(0);
		}
	else dfs(1,0);
	cout<<anss;
	return;
	}
signed main()
	{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	while(t--)sol();
	return 0;
	}

