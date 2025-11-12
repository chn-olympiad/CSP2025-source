#include<bits/stdc++.h>
using namespace std;
int a[5005],n,cnt;
const int mod=998244353;
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=7;i<(1<<n);++i)
	{
		int j=i,sum=0,mx=0,m=0;
		for(int k=1;k<=n;k++,j>>=1)if(j%2==1)sum+=a[k],mx=max(mx,a[k]),m++;
		if(sum>(mx<<1) && m>2)cnt++;
		cnt%=mod;
	}
	cout<<cnt;
	return 0;
}
