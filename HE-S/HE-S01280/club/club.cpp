#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int T,n,a[5][N];
ll f[250][250][250];
bool f1=1,f2=1;
void SubA(){
	sort(a[1]+1,a[1]+1+n);ll ans=0;
	for(int i=n;i>n/2;i--) ans+=a[1][i];
	cout << ans << '\n';
}
bool cmp(int a,int b){return a>b;}
void SubB(){
	int dis[N]={};ll ans=0;
	for(int i=1;i<=n;i++){
		dis[i]=a[2][i]-a[1][i];
		ans+=a[1][i];
	}
	sort(dis+1,dis+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=dis[i];
	}
	cout << ans << '\n';
}
void Sub(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k+j<=i;k++){
				if(j<=n/2 && j>0){
					f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[1][i]);
				}
				if(k<=n/2 && k>0){
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[2][i]);
				}
				if(i-j-k<=n/2 && i-j-k>0){
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[3][i]);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			ans=max(ans,f[n][i][j]);
		}
	}
	cout << ans << '\n';
	memset(f,0,sizeof(f));
}
void solve(){
	cin>>n;f1=1,f2=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[j][i];
		}
		if(a[3][i]!=0) f1=f2=0;
		if(a[2][i]!=0) f1=0;
	}
	if(f1){SubA();return;}
	if(f2){SubB();return;}
	if(n<=240){Sub();return;}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=max({a[1][i],a[2][i],a[3][i]});
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
