#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}
const int N=1e5+10;
struct node{
	int a,b,c;
}a[N];
struct node1{
	int a,b;
}a1[N],a2[N],a3[N];
int b[N];
inline int work(node1 a[],int n){
	int ans=0;
	for (int i=1;i<=n;i++) b[i]=a[i].b-a[i].a,ans+=a[i].a;
	sort(b+1,b+n+1,greater<int>());
	for (int i=1;i<=n/2;i++) ans+=b[i];
	return ans;
}
/*
1
6
10 0 0
10 0 0
0 10 0
0 10 0
0 0 10
0 0 10
*/
int f[110][110][110];
inline void solve(){
	int n=read();
	if (n<=200){
		for (int i=1;i<=n;i++) a[i]={read(),read(),read()};
		int ans=0;
		for (int i=0;i<=n/2;i++)
			for (int j=0;j<=n/2;j++)
				for (int k=0;k<=n/2;k++) if (i+j+k<n){
					if (i+1<=n/2) f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+j+k+1].a);
					if (j+1<=n/2) f[i][j+1][k]=max(f[i][j+1][k],f[i][j][k]+a[i+j+k+1].b);
					if (k+1<=n/2) f[i][j][k+1]=max(f[i][j][k+1],f[i][j][k]+a[i+j+k+1].c);
				}
				else if (i+j+k==n) ans=max(ans,f[i][j][k]);
		for (int i=0;i<=n/2;i++)
			for (int j=0;j<=n/2;j++)
				for (int k=0;k<=n/2;k++) f[i][j][k]=0;
		printf("%lld\n",ans);
		return ;
	}
	for (int i=1;i<=n;i++) a[i]={read(),read(),read()};
	for (int i=1;i<=n;i++){
		a1[i]={a[i].a,max(a[i].b,a[i].c)};
		a2[i]={a[i].b,max(a[i].a,a[i].c)};
		a3[i]={a[i].c,max(a[i].b,a[i].a)};
	}
	printf("%lld\n",max(max(work(a1,n),work(a2,n)),work(a3,n)));
}
main(){
//	system("fc club.out club4.ans");
//	freopen("club4.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}

