#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5*5;
int n,k,a[N*5];
int ans=0;
bool b[N*5];
bool check(int x,int y)
{
	for(int i=x;i<=y;i++)
	{
		if(b[i]==1)return 0;
		else b[i]=1;
	}
	return 1;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			for(int i1=i;i1<=j;i1++)sum=sum^a[i1];
			if(sum==k&&check(i,j))ans++;
		}
	 } 
	 cout << ans;
	 return 0;
}
