#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],x[500005],maxn;
void Xor(int m,int ans)
{
	if (a[m]==k)
	{
		ans++;
		maxn=max(maxn,ans);
		Xor(m-1,ans);
		return ;
	}
	for (int i=m-1;i>=0;i--)
		if ((x[m]^x[i])==k)
		{
			ans++;
			maxn=max(maxn,ans);
			if (i!=0)
				Xor(i,ans);
			return ;
		}
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	x[1]=a[1];
	for (int i=2;i<=n;i++)
		x[i]=x[i-1]^a[i];
	Xor(n,0);
	cout<<maxn;
	return 0;
}
