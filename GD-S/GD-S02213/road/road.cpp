#include<bits/stdc++.h>
using namespace std;
namespace IO{
	void read(long long &x){
		short f=1;x=0;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
		x*=f;
		return;
	}
	void out_(long long x){
		if(x>9) out_(x/10);
		putchar(x%10+'0');
		return;
	}
	void out(long long x){
		if(x<0) putchar('-'),x=-x;
		out_(x);putchar(' ');
		return;
	}
}using namespace IO;
char st;
const long long N=2e6+5,inf=1e18;
long long n,m,k,f[N],cnt;
struct node{long long x,y,z;}d[N],e[N],now[N];
long long val[15][N],c[15];
long long getfa(long long x){
	if(f[x]==x) return x;
	return f[x]=getfa(f[x]);
}
char ed;
void file(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	return;
}
bool cmp(node x,node y){return x.z<y.z;}
int main(){
	file();
	read(n),read(m),read(k);
	for(long long i=1;i<=n;i++) f[i]=i;
	for(long long i=1;i<=m;i++){
		long long x,y,z;
		read(x),read(y),read(z);
		d[i]=(node){x,y,z};
	}
	for(long long i=1;i<=k;i++){
		read(c[i]); 
		for(long long j=1;j<=n;j++) read(val[i][j]);
	}
	sort(d+1,d+m+1,cmp);
	long long maxn=0;
	for(long long i=1;i<=m;i++){
		long long x=getfa(d[i].x),y=getfa(d[i].y);
		if(x!=y) f[x]=y,e[++cnt]=(node){d[i].x,d[i].y,d[i].z},maxn=d[i].z;
	}
	long long ans=inf;
	for(long long s=0;s<(1<<k);s++){
		long long res=0,tot=0;
		for(long long i=1;i<=k;i++)
			if((s>>(i-1))&1){
				res+=c[i];
				for(long long j=1;j<=n;j++)
					if(val[i][j]<maxn) now[++tot]=(node){n+i,j,val[i][j]};
			}
		for(long long i=1;i<=cnt;i++) now[++tot]=e[i];
		sort(now+1,now+tot+1,cmp);
		for(long long i=1;i<=n+k;i++) f[i]=i;
		for(long long i=1;i<=tot;i++){
			long long x=getfa(now[i].x),y=getfa(now[i].y);
			if(x==y) continue;
			f[x]=y;
			res+=now[i].z;
		}
		ans=min(ans,res);
	}
	out(ans);
	return 0;
}

