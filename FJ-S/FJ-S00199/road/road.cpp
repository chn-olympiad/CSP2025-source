#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define her1 20081214
#define IV void
#define cht 998244353
#define ull unsigned long long
#define mem(x,val) memset(x,val,sizeof x)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#undef ll
using i64 = int;
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
const int maxn = 1e4+10+5;
const int maxm = 1e6+5;
const long long oo = 1e18;
i64 n,m,k,a[11][maxn],fa[maxn];long long Ans=oo;
i64 find(i64 x){return fa[x]==x?x:fa[x]=find(fa[x]);}
vector<array<i64,3> >p[maxn];

#define poly vector<array<i64,3> >
poly operator+(const poly&A,const poly&B){
	poly nw;
	i64 p1=0,p2=0;
	while(p1<A.size()&&p2<B.size()){
		if(A[p1]<B[p2])nw.push_back(A[p1++]);
		else nw.push_back(B[p2++]);
	}
	while(p1<A.size())nw.push_back(A[p1++]);
	while(p2<B.size())nw.push_back(B[p2++]);
	return nw;
}
poly adjust(poly V){
	F(i,1,n+k)fa[i]=i;
	vector<array<i64,3> >vn;
	for(auto[w,x,y]:V){
		x=find(x);y=find(y);if(x==y)continue;
		// cout<<x<<' '<<y<<endl;
		fa[y]=x;vn.push_back({w,x,y});
	}
	return vn;
}
IV dfs(i64 u,long long c,vector<array<i64,3> >V){
	// cout<<u<<' '<<c<<endl;
	// cout<<V.size()<<endl;
	if(u==k+1){
		for(auto[w,x,y]:V)c+=w;
		Ans=min(Ans,c);
		return;
	}
	dfs(u+1,c,V);
	dfs(u+1,c+a[u][0],adjust(V+p[u]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	vector<array<i64,3> >org;
	F(i,1,m){
		i64 u=read(),v=read(),w=read();
		org.push_back({w,u,v});
	}
	F(i,1,k){
		F(j,0,n)a[i][j]=read();
		F(j,1,n)p[i].push_back({a[i][j],n+i,j});
		sort(p[i].begin(),p[i].end());
	}
	sort(org.begin(),org.end());
	dfs(1,0,adjust(org));

	cout<<Ans;
	return 0;
}