#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN=1e6;
int a[MAXN];
int m; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int sum=a[i];
		for(int j=i;j<=n;j++)
		{
			sum+=sum^a[j];
			if(sum==m)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

