#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
struct edge {
	int u,v,w;
}a[M];
int f[N];
int n,m,k,x,num,ans;
int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
bool cmp(edge u,edge v) {
	return u.w<v.w;
}
int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void kruskal() {
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) {
		if(find(a[i].u)!=find(a[i].v)) {
			f[find(a[i].v)]=find(a[i].u);
			num++;
			ans+=a[i].w;
		}
		if(num==n-1) break; 
	}
	printf("%d\n",ans);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) a[i].u=read(),a[i].v=read(),a[i].w=read();
	for(int i=1;i<=k;i++) for(int j=1;j<=n+1;j++) x=read();
	kruskal();
	return 0;
}
