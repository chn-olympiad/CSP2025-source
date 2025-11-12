#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N]={0},sum[N]={0},s,ans=0,lj;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		s=i;
		lj=0;
		for(int j=i;j<=n;j++)
		{
			if((sum[j]^sum[s-1])==k)
			{
				lj++;
				s=j+1;
			}
		}
		ans=max(ans,lj);
	}
	cout<<ans;
}