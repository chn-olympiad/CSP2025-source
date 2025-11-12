#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,k,a[N],d[N],f[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	d[1]=a[1];
	for(int i=2;i<=n;i++)
		d[i]=d[i-1]^a[i];
	int now=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans++;
			now=i;
			continue;
		}
		for(int j=i-1;j>now;j--)
		{
			if((d[i]^d[j])==k)
			{
				ans++;
				now=i;
			}
		}
	}
	cout<<ans;
	return 0;
}

