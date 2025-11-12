#include<bits/stdc++.h>
using namespace std;

int n,arr[5010],ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				int ind[3];
				ind[1]=i;
				ind[2]=j;
				ind[0]=k;
				sort(ind,ind+3);
				if(arr[ind[2]]*2<arr[ind[1]]+arr[ind[0]])
					ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
