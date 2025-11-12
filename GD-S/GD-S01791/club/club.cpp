#include<bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof a)
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
namespace qwq {

const int N=1e5+10;
int n,a[N][4];
namespace sol1 {
	const int N=210;
	ll f[N][N][N];
	void sol() {
		mst(f,-0x3f),f[0][0][0]=0;
		for(int i=1;i<=n;i++) for(int j=0;j<=i;j++) for(int k=0;k<=i;k++) {
			if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
			if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
			f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
		}
		ll as=f[0][0][1];
		for(int i=0;i<=n/2;i++) for(int j=0;j<=n/2;j++) if(i+j>=n/2) as=max(as,f[n][i][j]);
		printf("%lld\n",as);
	}
}
namespace sol2 {
	pii p[N];
	void sol() {
		for(int i=1;i<=n;i++) p[i]={a[i][1],a[i][2]};
		sort(p+1,p+1+n,[&](pii x,pii y) {return x.fir-x.sec>y.fir-y.sec;});
		ll sm=0;
		for(int i=1;i<=n;i++) sm+=a[i][2];
		for(int i=1;i<=n/2;i++) sm+=p[i].fir-p[i].sec;
		printf("%lld\n",sm);
	}
}
namespace sol3 {
	struct NODE {int a,b,c;} p[N];
	void sol() {
		for(int i=1;i<=n;i++) p[i]={a[i][1],a[i][2],a[i][3]};
		sort(p+1,p+1+n,[&](NODE x,NODE y) {return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);});
		for(int i=0;i<=n/2;i++) {
			if(i) {
			}
		}
	}
}
void main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	sol2::sol();
	if(n<=200) return sol1::sol();
	int fg=1;
	for(int i=1;i<=n;i++) fg&=!a[i][3];
	if(fg) return sol2::sol();
	return sol3::sol();
}

}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) qwq::main();
}
/*
T1不会怎么办？
请看VCR
受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 受着 
*/ 
