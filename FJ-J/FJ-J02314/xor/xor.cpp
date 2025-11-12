#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	int n,y,ans=0;
	cin>>n>>y;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==y)
			ans++;
	}
//	int x=0;
//	for(int i=0;i<=n-1;i++)
//	{
//		for(int j=i;j<=n;j++)
//		{
//			for(int k=i;k<=j;k++)
//			{
//				x+=a[j]^a[i];
//			}
//			if(x==y)
//			{
//				ans++;
//			}
//			x=0;
//		}
//	}
	cout<<ans;
	return 0;
}
