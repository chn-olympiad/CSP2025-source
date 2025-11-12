#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node{
	int u,v,w;
}r[M+15];
int n,m,k,ans,f[N],c[15],a[15][N];
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
	return ;
}
inline bool cmp(node a,node b){
	return a.w<b.w;
}
inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
inline void merge(int x,int y){
	f[find(x)]=find(y);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		r[i].u=read();
		r[i].v=read();
		r[i].w=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(r[i].u)!=find(r[i].v)){
			merge(r[i].u,r[i].v);
			ans+=r[i].w;
		}
	}
	print(ans);
	return 0;
}
