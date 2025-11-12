#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005];
int fdst(int ed)
{
	long long tem=b[ed+1];
	for (int i=ed+1;i<=b[ed+1];i++) 
	{
		if (i>n) break;
		tem=min(tem,b[i]);
	}
	return tem;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++)
	{
		long long t=0;
		for (int j=i;j<=n;j++) 
		{
			t=t^a[j];
			if (t==k) 
			{
				b[i]=j;	
				break;
			}
		}
		if (t!=k) b[k]=n+1;
	}
	int pos=0,cnt=0;
	while (pos<n)
	{
		int t=fdst(pos);
		pos=b[t];
		cnt++;
	}
	cout << cnt;
	return 0;
}
