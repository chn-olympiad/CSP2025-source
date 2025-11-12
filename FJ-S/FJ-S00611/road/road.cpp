#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
ll read(){
	ll w=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return w*x;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar((x%10)+'0');
}
struct graph{
	int u,v;
	ll w;
	graph(int U=0,int V=0,int W=0):u(U),v(V),w(W){}
	bool operator <(const graph& rhs)const{
		return w<rhs.w;
	}
}g[M];
int n,m,k,c[N],fa[N],mstans,mstcnt;
int findset(int x){
	return fa[x]==x?x:fa[x]=findset(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		g[i].u=read(),g[i].v=read(),g[i].w=read();
	}
	sort(g+1,g+1+m);
	//kruskal
	for(int i=1;i<=m;i++){
		int f1=findset(g[i].u),f2=findset(g[i].v);
		if(f1==f2) continue;
		fa[f1]=f2;
		mstans+=g[i].w;
		mstcnt++;
		if(mstcnt==n-1) break;
	}
//	if(k==0){
		write(mstans);
		return 0;
//	}
	//5 mins left, i'm thinking the way i dead
	//afo
	fclose(stdin);
	fclose(stdout);
	return 0;
}