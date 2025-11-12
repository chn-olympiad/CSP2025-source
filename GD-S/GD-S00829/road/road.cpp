#include<bits/stdc++.h>
using namespace std;
const int N=1<<21;
char in[N],*p1=in,*p2=in,out[N],*p3=out;
inline char gc(){
	return p1==p2&&(p2=(p1=in)+fread(in,1,N,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
inline void read(T &x){
	x=0;
	char c=gc();
	while(!isdigit(c)) c=gc();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=gc();
	}
}
long long n,m,k,f[10010],idx,ans;
struct nd{
	long long u,v,w;
}d[2000010];
bool cmp(nd x,nd y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]=x) return x;
	return f[x]=x;
}
void krus(){
	int s=0;
	for(int i=1;i<=idx;i++){
		int tx=find(d[i].u),ty=find(d[i].v);
		if(tx!=ty){
			f[tx]=ty;
			ans+=d[i].w;
			s++;
			if(s==n-1) return;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	long long u,v,w;
	for(int i=1;i<=m;i++){
		read(u);read(v);read(w);
		d[++idx]={u,v,w};
		d[++idx]={v,u,w};
	}
	for(int i=1;i<=n;i++) f[i]=i;
	
	int x;
	bool f=true;
	for(int i=1;i<=k;i++){
		read(x);
		if(x!=0) f=false;
		for(int i=1;i<=n;i++){
			read(x);
			d[++idx]={i,m+idx,x};
			d[++idx]={m+idx,i,x};
		}
	}
	sort(d+1,d+idx+1,cmp);
	krus();
	cout<<ans<<endl;
	return 0;
}
