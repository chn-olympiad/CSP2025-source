#include<bits\stdc++.h>
using namespace std;
int n,m,ans;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int minn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=0;
		for(int j=i;j>minn;j--)
		{
			x^=a[j];
			if(x==m)
			{
				minn=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
