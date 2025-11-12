#include<bits/stdc++.h>
using namespace std;
#define N 10100
#define M 1000100
#define int long long
#define ps puts("")
#define pc putchar(' ')
#define f(i,l,r) for(i=l;i<=r;++i)
int n,m,k,tot,ans,cnt;
int change[N][15],fa[N];
struct edge{
	int u,v,w;
}e[M],tmp[M];
bool cmp(edge i,edge j){return i.w<j.w;}
int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}
int read(){
	int res=0ll,f=1ll;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void write(int x){
	static int st[40],top=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x) st[++top]=x%10,x/=10;
	if(!top) st[++top]=0;
	while(top) putchar(st[top--]^48);
	return ;
}
int mn(int len,int sum){
	int i,j,res=0;
	cnt=0;
	f(i,1,len) tmp[i]=e[i];
	sort(e+1,e+len+1,cmp);
	f(i,1,n+k) fa[i]=i;
	f(i,1,len){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			res+=w;
		}
		if(cnt==sum-1) break;
	}
	f(i,1,len) e[i]=tmp[i];
	return res;
}
void dfs(int i,int len,int sum,int res){
	if(i>k){
		ans=min(ans,mn(len,sum)+res);
		return ;
	}
	for(int j=1;j<=n;++j) e[len+j]=edge{i+n,j,change[j][i]};
	dfs(i+1,len+n,sum+1,res+change[0][i]);
	dfs(i+1,len,sum,res);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,u,v,w;
	n=read(),m=read(),k=read();
	f(i,1,n) fa[i]=i;
	f(i,1,m){
		u=read(),v=read(),w=read();
		e[i]=edge{u,v,w};
	}
	sort(e+1,e+m+1,cmp);
	f(i,1,m){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=w;
			e[++tot]=edge{u,v,w};
		}
		if(tot==n-1) break;
	}
	f(j,1,k) f(i,0,n) change[i][j]=read();
	if(k) dfs(1,n-1,n,0);
	write(ans);ps;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
1~4:最小生成树 
A:最小生成树
*/

