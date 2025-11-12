//IN
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,K=12;
const int M=1e6+N*K;
struct daolu {
	int u,v,w;
} a[M];
bool cmp(daolu x,daolu y) {
	return x.w<y.w;
}
int f[N+K];
int get(int x) {
	if(x==f[x]) return x;
	else return f[x]=get(f[x]);
}
int n,m,k,cnt;
int ct[K][N];
bool fl[K];
ll ans;
int read() {
	int res=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		res=res*10+(c-'0');
		c=getchar();
	}
	return res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	scanf("%d %d %d",&n,&m,&k);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) {
		//scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	cnt=m;
	for(int i=1;i<=k;i++) {
		for(int j=0;j<=n;j++) {
			//scanf("%d",&ct[i][j]);
			ct[i][j]=read();
			if(j!=0) a[++cnt]={n+i,j,ct[i][j]};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	ans=1e17;
	for(int i=0;i<=(1<<k)-1;i++) {
		int pos=1,nwd=n;
		ll res=0;
		for(int j=1;j<=k;j++) {
			if((i^pos)==i-pos) fl[j]=1,nwd++,res+=ct[j][0];
			pos<<=1;
		}
		if(res>=ans) {
			for(int j=1;j<=k;j++) fl[j]=0;
			continue;
		}
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(int j=1;j<=cnt;j++) {
			if(res>=ans) break;
			int fr=a[j].u,tt=a[j].v;
			if(fr>n) {
				if(!fl[fr-n]) continue;
			}
			if(get(fr)==get(tt)) continue;
			f[get(fr)]=tt;
			res+=1ll*a[j].w;
			nwd--;
			if(nwd==1) break;
		}
		if(res<ans) ans=res;
		for(int j=1;j<=k;j++) fl[j]=0;
	}
	cout<<ans;
}
/*
神秘剪枝+快读
再给我一点分吧 
*/
