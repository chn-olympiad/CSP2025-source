#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const long long m = 998244353;
long long n,ans,k,sum1003,mx123,cnt,a[105],f[N];
bool flag;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	flag = 1;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag = 0;
		}
	}
	if(flag){
		f[1] = 0;
		for(int i = 2;i<=N;i++){
			f[i] = (f[i-1]*2+1)%m;
		}
		for(int i = 2;i<=N;i++){
			f[i] = (f[i-1]+f[i])%m;
		}
		for(int i = 2;i<=N;i++){
			f[i] = (f[i-1]+f[i])%m;
		}
		cout<<f[n-1];
		return 0; 
	}
	ans = 0;
	for(long long i = 1;i<=(1<<n)-1;i++){
		sum1003 = 0;
		mx123 = 0;
		cnt = 0;
		for(long long j = 0;j<=n-1;j++){
			if((i>>j)&1){
				cnt++;
				sum1003+=a[j+1];
				mx123 = max(mx123,a[j+1]);
			}
		}
		if(cnt<3){
			continue;
		}
		if(sum1003>2*mx123){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}