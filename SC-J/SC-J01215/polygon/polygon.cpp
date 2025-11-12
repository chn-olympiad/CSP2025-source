#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],f[N][N],ans;//f(i,j)表示对于前i根木棍选出大于j的长度的个数
int sf(int i,int j){return j>=0?f[i][j]:1;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,p2=1;i<=n;++i){
		for(int j=0;j<=a[n];++j)
			f[i][j]=(f[i-1][j]+(a[i]>j?p2:f[i-1][j-a[i]]))%mod;
		(p2<<=1)%=mod;
	}
//	for(int i=1;i<=n;++i)
//		for(int j=0;j<=a[n];++j)
//			cout<<"f("<<i<<','<<j<<")="<<f[i][j]<<'\n';
	for(int i=1;i<=n;++i)
		(ans+=f[i-1][a[i]])%=mod;
	cout<<ans;
	return 0;
}