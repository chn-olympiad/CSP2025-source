#include<bits/stdc++.h>
using namespace std;
const int N=1e3*5+10;
int a[N],p[N],m[N],pre[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	mx*=2;
	long long ans;
	int cnt=2;
	while(cnt!=n)
	{
		pre[cnt-1]=a[cnt-1];
		for(int i=cnt;i<=n;i++)
		{
			pre[i]=pre[i-1]+a[i];
			if(pre[i]>mx)
			{
				ans++;
			}
			p[i]=p[i-1]+a[i+1]+a[i+2];
			if(p[i]>mx)
			{
				ans++;
			}
		}
		cnt++;
	}
	cout<<ans%998244353-cnt;  
	return 0;
} 