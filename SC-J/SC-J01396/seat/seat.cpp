#include<bits/stdc++.h>
#define itn int
#define pb push_back
#define ll long long
#define endl '\n'
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=15;
int n,m,t,a[N*N],p[N][N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int u=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				p[i][j]=a[++u];
			}
		}
		if(j%2==1){
			for(int i=1;i<=n;i++){
				p[i][j]=a[++u];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]==t){
				cout<<j<<' '<<i;
				return;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
		Solve();
	return 0;
}

