#include<bits/stdc++.h>
#define ll long long
#define il inline
#define mst(a,x) memset(a,x,sizeof a)
using namespace std;
namespace qwq {
const int N=510,MOD=998244353;
il int vmod(int x) {return x>=MOD?x-MOD:x;}
il int vadd(int x,int y) {return vmod(x+y);}
il int vsub(int x,int y) {return vmod(x-y+MOD);}
il int vmul(int x,int y) {return 1ll*x*y%MOD;}
il void cadd(int &x,int y) {x=vmod(x+y);}
il void csub(int &x,int y) {x=vmod(x-y+MOD);}
il void cmul(int &x,int y) {x=1ll*x*y%MOD;}
il int qpow(int a,int b) {
	int rs=1;
	while(b) {
		if(b&1) cmul(rs,a);
		cmul(a,a),b/=2;
	}
	return rs;
}
int n,m,a[N],c[N],fc[N],ifc[N];
void init(int n) {
	fc[0]=1;
	for(int i=1;i<=n;i++) fc[i]=vmul(fc[i-1],i);
	ifc[n]=qpow(fc[n],MOD-2);
	for(int i=n-1;~i;i--) ifc[i]=vmul(ifc[i+1],i+1);
}
il int C(int x,int y) {
	if(x<y) return 0;
	return vmul(fc[x],vmul(ifc[y],ifc[x-y]));
}
namespace sol1 {
	const int M=18;
	int f[1<<M][M+1];
	//当前来了状态为s，录用了i个人 
	void sol() {
		f[0][0]=1;
		for(int s=1;s<1<<n;s++) {
			for(int i=1;i<=n;i++) if(s>>i-1&1) {
				int pp=__builtin_popcount(s);
				for(int j=0;j<=pp;j++) {
					if(!a[pp]||pp-j-1>=c[i]) cadd(f[s][j],f[s^1<<i-1][j]);
					if(j&&a[pp]&&pp-j<c[i]) cadd(f[s][j],f[s^1<<i-1][j-1]);
				}
			}
//			for(int i=0;i<=n;i++) printf("%d %d %d\n",s,i,f[s][i]);
		} 
		int as=0;
		for(int i=m;i<=n;i++) {
			cadd(as,f[(1<<n)-1][i]);
//			printf("%d %d\n",as,f[(1<<n)-1][i]);
		}
		printf("%d\n",as);
	}
}
namespace sol2 {
	void sol() {
		int as=1;
		for(int i=1;i<=n;i++) if(!a[i]||!c[i]) as=0;
		for(int i=1;i<=n;i++) cmul(as,i);
		printf("%d\n",as);
	}
}
namespace sol3 {
	int as,sm[N];
	void sol() {
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i]&&c[j]>=i) {
			mst(sm,0);
			for(int k=1;k<=n;k++) if(j!=k) sm[c[k]]++;
			for(int k=1;k<=n;k++) sm[k]+=sm[k-1];
			int cr=1,c=0;
			for(int k=1;k<i;k++) if(a[k]) {
				if(sm[k-1]<=c) cr=0;
				else cmul(cr,sm[k-1]-c);
				c++;
			}
			cadd(as,vmul(cr,fc[n-c-1]));
		}
		printf("%d\n",as);
	}
}
void main() {
	scanf("%d%d",&n,&m),init(N-10);
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n<=18) return sol1::sol();
	if(m==n) return sol2::sol();
	if(m==1) return sol3::sol();
}

}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	qwq::main();
}
/*
10 10
1111111111
6 1 4 2 1 2 5 4 3 3

while(1) system("taskkill /f /im studentmain.exe");
*/

