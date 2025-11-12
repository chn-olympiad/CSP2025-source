#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define g(i,j,k) for(int i=j;i>=k;--i)
int n,m,s,l;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;'0'>ch||ch>'9';ch=getchar())if(ch=='-')f=-f;
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f; 
}
void write(int x){if(x>9)write(x/10);putchar(x%10+48);}
const int N=2e6,M=2e4;
struct eg{int x,y,z;}a[N],b[13][M],c[13][M];
inline bool operator<(eg a,eg b){return a.z<b.z;}
int fa[N];
int fifa(int x){return x==fa[x]?x:fa[x]=fifa(fa[x]);}
inline void clc(int&u,eg*a){
	int m=u,x,y;u=0;
	f(i,1,n+s)fa[i]=i;
	f(_,1,m)if((x=fifa(a[_].x))!=(y=fifa(a[_].y)))a[++u]=a[_],fa[x]=y;
}
void dfs(int t,int m,int w){
	if(t==s){
		f(i,1,m)w+=c[t][i].z;
		l=min(l,w);
		return;
	}
	f(i,1,m)c[t+1][i]=c[t][i];
	dfs(++t,m,w);
	merge(c[t-1]+1,c[t-1]+m+1,b[t]+1,b[t]+n+1,c[t]+1);
	m+=n;clc(m,c[t]);dfs(t,m,w+b[t][0].z);
} 
inline void doing(){
	n=read();m=read();s=read();l=0;
	f(i,1,m)a[i].x=read(),a[i].y=read(),a[i].z=read();
	sort(a+1,a+m+1);clc(m,a);
	f(t,1,s){
		b[t][0].z=read();
		f(i,1,n)b[t][i]={i,n+t,read()};
		sort(b[t]+1,b[t]+n+1);
	}
	f(i,1,m)c[0][i]=a[i],l+=a[i].z;
	dfs(0,m,0);write(l);putchar('\n');
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t=1;
	while(t--)doing();
}
