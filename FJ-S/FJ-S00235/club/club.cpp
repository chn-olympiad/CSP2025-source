#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define N 200005
#define INF (ll)1e18

using namespace std;
inline ll rd(){
	ll res=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48), ch=getchar();
	return res*f;
}
ll n, a[N][4], ans, cnt1, cnt2, cnt3;
ll dp[205][205][205];
ll q[N];
struct Node{
	ll x, y;
}b[N];
void solve1(){
//	puts("awa");
	dp[0][0][0]=ans=0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=i&&j<=n/2; j++){
			for(int k=0; j+k<=i&&k<=n/2; k++){
				if(i-j-k>n/2) continue;
				dp[i][j][k]=dp[i-1][j][k]+a[i][3];
				if(j) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j-1][k]+a[i][1]);
				if(k) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]+a[i][2]);
			}
		}
	}
	for(int i=0; i<=n&&i<=n/2; i++){
		for(int j=0; i+j<=n&&j<=n/2; j++){
			if(n-i-j>n/2) continue;
//			cout<<dp[n][i][j]<<' ';
			ans=max(ans, dp[n][i][j]);
		}
//		puts("");
	}
	printf("%lld\n", ans);
}
void solve2(){
	ll ans=0;
	for(int i=1; i<=n; i++) q[i]=a[i][2]-a[i][1], ans+=a[i][1];
	sort(q+1, q+n+1, greater<ll>());
	for(int i=1; i<=n/2; i++) ans+=q[i];
	printf("%lld\n", ans);
}
void solve3(){
	n=rd(), ans=0, cnt1=n, cnt2=cnt3=0;
	for(int i=1; i<=n; i++) a[i][1]=rd(), a[i][2]=rd(), a[i][3]=rd(), ans+=a[i][1];
	for(int i=1; i<=n; i++) b[i].x=a[i][2]-a[i][1], b[i].y=a[i][3]-a[i][1];
	sort(b+1, b+n+1, [](Node x, Node y){return min(x.x, x.y)<min(y.x, y.y);});
	for(int i=1; i<=n; i++){
		if(min(b[i].x, b[i].y)<0||cnt1>=n/2){
			ans+=min(b[i].x, b[i].y), cnt1--; 
			if(min(b[i].x, b[i].y)==b[i].x) cnt2++;
			else cnt3++;
		}
	}
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) return printf("%lld\n", ans), void();
}
void solve(){
	n=rd(), ans=0;
	for(int i=1; i<=n; i++) a[i][1]=rd(), a[i][2]=rd(), a[i][3]=rd();
//	for(int i=1; i<=n; i++) q[i].x=a[i][2]-a[i][1], q[i].y=a[i][3]-a[i][1];
//	puts("awa");
	if(n<=200) solve1();
	else if(a[1][3]==0) solve2();
	else solve3();
//	sort(q+1, q+n+1, [](Node x, Node y){return max(x.x, x.y)>max(y.x, y.y)});
}
int main(){
	freopen("club3.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	for(ll tt=rd(); tt--; ) solve();
	
	return 0;
} 
/*

*/
