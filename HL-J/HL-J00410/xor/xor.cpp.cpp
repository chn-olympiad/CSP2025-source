#include<bits/stdc++.h>
using namespace std;
int yd[1000100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>yd[i];
	}
	for(int i=1;i<=n;i++)
	{
		int c=yd[i];
		if(c==k) ans++;
		else
		{
			int j;
			for(j=i+1;j<=n;j++)
			{
				c=c^yd[j];
				if(c==k) break;
			}
			ans++;
			i=j+1;
		}
	}
	cout<<ans;
	return 0;
}
