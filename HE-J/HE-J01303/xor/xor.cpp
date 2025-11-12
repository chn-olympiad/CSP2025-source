#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
void t(int l,int r)
{
	int z=a[l];
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]==-1) return;
		z^=a[i];
	}
	if(z==k)
	{
		ans++;
		for(int i=l;i<=r;i++) a[i]=-1;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			t(i,j);
		}
	}
	cout<<ans;
	return 0;
}
