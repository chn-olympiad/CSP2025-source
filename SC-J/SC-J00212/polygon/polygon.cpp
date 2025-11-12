#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353,N=1e4,M=1e15;
int cnt[10005],a[5005];
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; cin >>n;
	for(int i=1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	cnt[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=N;j++) ans+=cnt[j];
		ans%=P;
		for(int j=N;j>=0;j--)
		{
			cnt[min(N,j+a[i])]+=cnt[j];
			if(cnt[min(N,j+a[i])]>M) cnt[min(N,j+a[i])]%=P;
		}
	}
	cout <<ans;
	return 0;
}