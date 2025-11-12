#include <bits/stdc++.h>
using namespace std;
int n,k,num,pre[500005],a[500005];
int pree(int l,int r)
{
	return pre[r]-pre[l];	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	pre[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(pree(j,i)==k)
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
