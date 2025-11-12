#include<bits/stdc++.h>
using namespace std;
const int N=204,M=1e5+4;
int T,n,f[N][N/2][N/2];
struct E{
	int a,b,c;
} a[M];
void solve2(){
	int ans=0;
	for(int i=1;i<=n;i++)ans+=max({a[i].a,a[i].b,a[i].c});
	cout<<ans<<'\n';
}
void solve1(){
	for(int i=1;i<=n;i++){
		if(a[i].c){
			solve2();
			return;
		}
	}
	int ans=0;
	sort(a+1,a+n+1,[](E a,E b){
		return a.b-a.a>b.b-b.a;
	});
	for(int i=1;i<=n/2;i++)ans+=a[i].b;
	for(int i=n/2+1;i<=n;i++)ans+=a[i].a;
	cout<<ans<<'\n';
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
	if(n>203){
		solve1();
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,n/2);j++){
			for(int k=max(i-j-n/2,0);k<=min(i-j,n/2);k++){
				f[i][j][k]=0;
				if(j)f[i][j][k]=f[i-1][j-1][k]+a[i].a;
				if(k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i].b);
				if(i-j-k)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].c);
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n/2;j++){
		for(int k=n/2-j;k<=n/2;k++)ans=max(ans,f[n][j][k]);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)solve();
}
