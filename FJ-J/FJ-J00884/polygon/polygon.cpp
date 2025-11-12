#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int f[N],a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3)
	{
		int cnt=0,maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
			cnt+=a[i];
		}
		if(2*maxn<cnt)cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)f[i]=a[i];
	for(int i=1;i<=n;i++)
	{
		int maxn=a[i];
		int cnt=1;
		for(int j=i+1;j<=n;j++)
		{
			maxn=max(maxn,a[j]);
		//	cout<<2*maxn<<f[i]+a[j];
			if(f[i]+a[j]>2*maxn)
			{
				f[i]=f[i]+a[j];
				cnt++;
				if(cnt>=3)ans++;
			}
			else
			{
				f[i]+=a[j];cnt++;
			}
		}
	}
	cout<<ans;
	return 0;
}
