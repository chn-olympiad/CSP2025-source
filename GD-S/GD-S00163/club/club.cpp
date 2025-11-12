#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e5 + 10, M = 210, K = 110;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int t,n,cnt[4],op[N],f[M][K][K],ans;
int a[N][4];
void solve1(){
	ans=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=(n>>1);j++){
			for (int k=0;k<=(n>>1);k++){
				f[i][j][k]=0;
				if (j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
				if (k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
				if (i-j-k && i-j-k<=(n>>1)) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
			}
		}
	}
	for (int j=0;j<=(n>>1);j++){
		for (int k=0;k<=(n>>1);k++){
			ans=max(ans,f[n][j][k]);
		}
	}
	cout << ans << "\n";
} 
int v[N];
void solve2(){
	ans=0;
	for (int i=1;i<=n;i++){
		ans+=a[i][1];
		v[i]=a[i][1]-a[i][2];
	}
	sort(v+1,v+n+1);
	int j=0;
	for (int i=1;(j<(n>>1)) && i<=n;i++,j++) ans-=v[i];
	cout << ans << "\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++) a[i][j]=read();
		}
		if (n<=200) solve1();
		else solve2();
	}
}
/*
²É¾Å¶äÁ«¡£ 
*/
