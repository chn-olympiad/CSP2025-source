#include <cstdio>
#include <cctype>
#define maxn 500005
#define int long long
#define max(a,b) (a>b?a:b)
using namespace std;

int n,k,cntr,cnt,ans,a[maxn];
struct seg{int l,r,u;} sgr[maxn],sg[maxn];

int read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch-48),ch=getchar();
	return x*f;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			t^=a[j];
			if(t==k) {sgr[++cntr].l=i,sgr[cntr].r=j; break;}
		}
	}
	for(int i=1;i<cntr;i++) for(int j=i+1;j<=cntr;j++){
		if(sgr[j].r<=sgr[i].r) {sgr[i].u=1; break;}
		else sgr[i].u=0;
	}
	for(int i=1;i<=cntr;i++) if(!sgr[i].u) sg[++cnt].l=sgr[i].l,sg[cnt].r=sgr[i].r;
	for(int i=1;i<=cnt;i++){
		int tans=1,r=sg[i].r;
		for(int j=i+1;j<=cnt;j++) if(sg[j].l>r) r=sg[j].r,tans++;
		ans=max(tans,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
