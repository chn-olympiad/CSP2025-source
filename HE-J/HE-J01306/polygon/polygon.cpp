#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5003,p=998244353;
int n,a[N],f[N][N],ans;
signed main(){
	freopen("polygon.in","r",stdin),
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<N-1;j++){
			f[i][j]=f[i-1][j];
			if(j>=a[i])
				(f[i][j]+=f[i-1][j-a[i]])%=p;
		}
		f[i][N-1]=f[i-1][N-1];
		for(int j=N-1-a[i];j<=N-1;j++)
			(f[i][N-1]+=f[i-1][j])%=p;
	}
	for(int i=n;i>=3;i--)
		for(int j=a[i]+1;j<N;j++)
			(ans+=f[i-1][j])%=p;
	cout<<ans;
	return 0;
}
//CSP-S RP++,maybe emm... I should sleep for a while to relax. 
