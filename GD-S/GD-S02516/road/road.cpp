#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define in(s1) freopen(s1,"r",stdin);
#define out(s1) freopen(s1,"w",stdout);
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
	x=0;
	char c=getchar();
	int f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=2e6+10;
int n,m,k,asdf=INT_MAX;
int h[11];
struct node{
	int u,v,w;
}a[N];
int cnt,c[N],g[11][N];
int father[N];
int find(int x){
	if(father[x]==x)return x;
	return father[x]=find(father[x]);
}
int kruskal(int q){
	for(int i=1;i<=n*2;i++)father[i]=i;
	sort(a+1,a+cnt+1,[&](node x1,node x2){
		return x1.w<x2.w;
	});
	int ans=0;
	int l=0;
	for(int i=1;i<=cnt;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y){
			father[x]=y;
			ans+=a[i].w;
			if(++l==n+q-1)break;
		}
	}
	return ans;
}
node b[N];
void dfs(int x){
	if(x>k){
		int ans=0;
		int q=0;
		for(int i=1;i<=k;i++){
			if(h[i]){
				q++;
				ans+=c[i];
				for(int j=1;j<=n;j++){
					cnt++;
					a[cnt].u=i+n,a[cnt].v=j,a[cnt].w=g[i][j];
				}
			}
		}
		ans+=kruskal(q);
		asdf=min(asdf,ans);
		cnt=m;
		for(int i=1;i<=m;i++)a[i].u=b[i].u,a[i].v=b[i].v,a[i].w=b[i].w;
		memset(h,0,sizeof(h));
		return ;
	}
	for(int i=0;i<=1;i++){
		h[x]=i;
		dfs(x+1);
		h[x]=0;
	}
	return ;
}
signed main(){
	in("road.in")
	out("road.out")
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)read(a[i].u),read(a[i].v),read(a[i].w),b[i].u=a[i].u,b[i].v=a[i].v,b[i].w=a[i].w;
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++)read(g[i][j]);
	}
	cnt=m;
	dfs(1);
	cout<<asdf;
	return 0;
}
/*

*/

