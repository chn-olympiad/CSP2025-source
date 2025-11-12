//GZ-S00499 贵阳市第一中学 黄世杰
#include<bits/stdc++.h>
using namespace std;
const long long N=510,M=998244353;
long long f[N][N];
long long n,m,a[N];
long long ans=0;
long long t=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;cin>>s;
	s=" "+s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		for(long long j=1;j<=i;j++){
			long long cj=i-j;
			long long cnt=upper_bound(a+1,a+n+1,cj)-a;
			f[i+1][j+1]=(f[i+1][j+1]+(f[i][j]*(max(t,n-cnt+1-j)))%M)%M;
			f[i+1][j]=(f[i+1][j]+(f[i][j]*(max(t,cnt-1-(i-j))))%M)%M;
		}
	}
	for(long long i=m;i<=n;i++){
		ans=(ans+f[n][i])%M;
	}
	cout<<ans%M<<endl;
	return 0;
} 
