#include<bits/stdc++.h>
using namespace std;
const long long N=5005,Mod=998244353;
long long a[N],f[3][N],p[N];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	f[0][0]=1;
	p[0]=1;
	for(int i=1;i<=n;i++)
		p[i]=(p[i-1]+p[i-1])%Mod;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[n];j++)
			f[i%2][j]=f[(i-1)%2][j];
		for(int j=0;j<=a[n];j++)
			f[i%2][j]=(f[i%2][j]+f[(i-1)%2][j-a[i]])%Mod;
		int x=p[i-1];
		for(int j=0;j<=a[i];j++)
			x=(x-f[(i-1)%2][j]+Mod)%Mod;
		ans=(ans+x)%Mod;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int QwQawaqaq=1;
	while(QwQawaqaq--)
		solve();
	return 0;
}
//希望 T1 T2 T3 T4 都能过
//my luogu uid is 1115541
//my luogu name is dong0717
//想要关注喵
