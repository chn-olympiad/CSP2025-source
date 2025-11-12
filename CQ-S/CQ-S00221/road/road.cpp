#include<stdio.h>
#include<algorithm>
#define ll long long
const int N=2e4+10;
const int M=1e6+10;
int fa[N];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
struct node{
	int x,y,z;
	bool operator<(const node &a)const{
		return z<a.z;
	}
}E[M],EE[M];
int n,m,k,c[N],a[11][N];
namespace io{
	const int SIZE=(1<<21)+10;
	char ibuf[SIZE],*iS,*iT,c;int f=1;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
	template<class I>
	void gi(I &x){
		for(c=gc(),f=1;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c>='0'&&c<='9';c=gc())x=x*10+(c&15);x*=f;
	}
}
using io::gi;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	gi(n),gi(m),gi(k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)gi(E[i].x),gi(E[i].y),gi(E[i].z);
	std::sort(E+1,E+m+1);
	for(int i=1,j=0;i<=m;i++){
		int fx=getfa(E[i].x),fy=getfa(E[i].y);
		if(fx!=fy){
			EE[++j]=E[i];fa[fx]=fy;
		}
	}int bs=n-1;
	for(int i=1;i<=k;i++){
		gi(c[i]);
		for(int j=1;j<=n;j++)gi(a[i][j]),EE[++bs]=node{n+i,j,a[i][j]};
	}
	std::sort(EE+1,EE+bs+1);
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		ll tot=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=k;j++){
			if(!(i&(1<<j-1)))continue;
			tot+=c[j];
		}
		for(int j=1;j<=bs;j++){
			if(EE[j].x>n&&!(i&(1<<EE[j].x-n-1)))continue;
			if(EE[j].y>n&&!(i&(1<<EE[j].y-n-1)))continue;
			int fx=getfa(EE[j].x),fy=getfa(EE[j].y);
			if(fx!=fy){
				tot+=EE[j].z;fa[fx]=fy;
			}
		}
		ans=std::min(ans,tot);
	}
	printf("%lld",ans);
	return 0;
}
