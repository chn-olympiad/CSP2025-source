#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define ll long long
#define D 998244353ll
ll n,s,a[N],f[N][N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<n;i++){
		s=min(s+a[i],a[n]+1);
		for(int j=0;j<a[i];j++)
			f[i][j]=(f[i-1][j]+f[i-1][0])%D;
		for(int j=a[i];j<=s;j++)
			f[i][j]=(f[i-1][j]+f[i-1][j-a[i]])%D;
		ans=(ans+f[i][a[i+1]+1])%D;
	}
	cout<<ans;
	return 0;
}
