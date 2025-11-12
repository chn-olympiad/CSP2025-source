#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int l=0;l<n;l++)
	{
		for(int r=l;r<n;r++)
		{
			int res=0;
			for(int i=l;i<=r;i++)
			{
				res=res^a[i];
			}
			if(res==k)
			{
				ans++;
				l=r+1;
				r++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
