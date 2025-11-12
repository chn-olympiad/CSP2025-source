#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
ll n,m,k,jk,ans,sum,num,cnt,tot,vv[12];
ll head[N],dis[N],vis[N],wis[12][N],kis[12],f[N];

void read(ll & x){
	x=0;ll ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));
}

struct P{
	ll x,y,z,p;
}v[N*12],pt[N*12];

//struct P{
//	ll nxt,val,to;
//}v[N*12];
//
//void add(ll x,ll y,ll z){
//	v[++cnt]=(P){head[x],z,y};
//	head[x]=cnt;return;
//}
//
//struct Q{
//	ll x,id;bool K[11];
//	bool operator<(const Q&A)const{
//		return A.x<x;
//	}
//};

bool cmp(P x,P y){
	return x.z<y.z;
}

ll Find(ll x){
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
}

void kruskal(){//wh(cnt);
	tot=0;
	for(ll i=1;i<=cnt;i++){
		ll x=Find(v[i].x),y=Find(v[i].y);
		if(v[i].p) pt[++tot]=(P){v[i].x,v[i].y,v[i].z,1};
		if(x==y||(v[i].x>n&&!kis[v[i].x-n])||(v[i].y>n&&!kis[v[i].y-n])) continue;
		f[x]=y;ans+=v[i].z;
	}
//	cnt=tot;
//	for(int i=1;i<=tot;i++) v[i].x=pt[i].x,v[i].y=pt[i].y,v[i].z=pt[i].z,v[i].p=pt[i].p;
	tot=0;return;
}

void kruskal1(){//wh(cnt);
	tot=0;
	for(ll i=1;i<=cnt;i++){
		ll x=Find(v[i].x),y=Find(v[i].y);
		if(x==y) continue;
		f[x]=y;ans+=v[i].z;pt[++tot]=(P){v[i].x,v[i].y,v[i].z,1};
	}cnt=tot;
	for(int i=1;i<=tot;i++) v[i].x=pt[i].x,v[i].y=pt[i].y,v[i].z=pt[i].z,v[i].p=pt[i].p;
	tot=0;return;
}

void dfs(ll x,ll y){
	if(y>=sum) return;
	if(x>k){ans=0;
		for(ll i=1;i<=n+k+1;i++) f[i]=i;
		stable_sort(1+v,1+v+cnt,cmp);
		kruskal();//wh(ans+y);
		sum=min(sum,ans+y);return;
	}
	for(ll i=1;i<=n&&!vv[x];i++) v[++cnt]=(P){x+n,i,wis[x][i],0};
	kis[x]=1;vv[x]=1;
	dfs(x+1,y+dis[x]);
	kis[x]=0;dfs(x+1,y);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(ll i=1,x,y,z;i<=m;i++){
		read(x),read(y),read(z);
		v[++cnt]=(P){x,y,z,1};
	}sort(1+v,1+v+cnt,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	kruskal1();sum=ans;
	for(ll i=1;i<=k;i++){
		read(dis[i]);
		for(ll j=1;j<=n;j++) read(wis[i][j]);
	}dfs(1,0);wh(sum);
	return 0;
}/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
