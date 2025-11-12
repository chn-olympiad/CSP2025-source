#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int sum[N];
int f[N];
int rb[N]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((sum[j]^sum[i-1])==k)
			{
				rb[i]=j;
				break;
			}
		}
//		cout<<rb[i]<<' ';
	}
	for(int i=n;i>=1;i--)
	{
		if(rb[i]) f[i]=max(f[i+1],f[rb[i]+1]+1);
		else f[i]=f[i+1];
	}
	cout<<f[1];
	return 0;	
} 