#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void write(ll k){
	if(k<0){
		k=-k;
		putchar('-');
	}
	if(k>9)
		write(k/10);
	putchar(k%10+'0');
}
/*
首先原有的m条边肯定只用最小生成树
暴力枚举用哪些点,然后跑最小生成树,排序在外面排,能够做到O(2^k*n*k)
但是这样并查集又要写路径压缩,又要写按秩合并
*/
int n,m,k,boss[10015],siz[10015],cnt,c[15],num;
ll ans=1e18;
struct node{
	int u,v,w;
	bool operator < (const node&t) const{
		return w<t.w;
	}
}a[1000005],b[10005],d[100005];
int find(int x){
	if(boss[x]!=x)
		return boss[x]=find(boss[x]);
	return x;
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)
		return false;
	if(siz[x]>siz[y])
		swap(x,y);
	boss[x]=y,siz[y]+=siz[x];
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++){
		boss[i]=i,siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		if(merge(a[i].u,a[i].v))
			b[++cnt]=a[i];
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			d[++num]={n+i,j,read()};
		}
	}
	sort(d+1,d+num+1);
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++){
			boss[j]=j,siz[j]=1;
		}
		ll sm=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1)
				sm+=c[j];
		}
		int j=1;
		for(int p=1;p<=num;p++){
			while(j<=cnt&&b[j].w<=d[p].w){
				if(merge(b[j].u,b[j].v))
					sm+=b[j].w;
				j++;
			}
			int id=d[p].u-n;
			if((i>>(id-1)&1)&&merge(d[p].u,d[p].v))
				sm+=d[p].w;
		}
		while(j<=cnt){
			if(merge(b[j].u,b[j].v))
				sm+=b[j].w;
			j++;
		}
		ans=min(ans,sm);
	}
	write(ans);
	return 0;
}