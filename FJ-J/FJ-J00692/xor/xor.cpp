#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int c=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
			ans++,c=i+1;
		else
		{
			int x=a[i];
			for(int j=i-1;j>=c;j--)
			{
				x^=a[j];
				if(x==k)
				{
					ans++,c=i+1;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}