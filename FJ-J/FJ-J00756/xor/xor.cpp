#include <bits/stdc++.h>
using namespace std;

int n,k,j,sum,ans;
int a[500005],x[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
		
	for(int l=1; l<=n; l++)
	{
		sum=0;
		for(int r=1; r<=n; r++)
		{
			j=x[l-1]^x[r];
			if(j == k)
			{
				sum++;
				l=r+1;
			}
		}
		
		ans=max(ans,sum);
	}
	
	cout<<ans;
	
	return 0;
}
