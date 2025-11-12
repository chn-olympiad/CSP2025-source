#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int addn=a[i];
		for(int j=i;j<=n;j++)
		{
			if(addn==k) 
			{
				ans++;
				i=j+1;
				break;
			}
			addn=addn^a[j];
		}
	}
	cout<<ans;
	return 0;
}
