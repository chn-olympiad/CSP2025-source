#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=0,k=0;
	cin>>n>>k;
	vector<int>v(n+1);
	int cnt=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>v[i];
	}
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int ret=0;
			for(int t=i;t<=j;t++)
			{
				ret^=v[t];
			}
			if(ret==k)
			{
				cnt++;
				l=i;
				r=j;
				i=j+1;
			}
		}
	}
	cout<<cnt<<endl; 
	return 0;
}
