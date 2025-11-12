#include<bits/stdc++.h>
using namespace std;
int a[500010],sum[500010];
long long ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j,k,n,m;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];//[l,r]=sum[r]^sum[l-1];
	}
	int last=0;
	for(i=1;i<=n;i++)
	{
		for(j=last;j<i;j++)
		{
			int t=sum[i]^sum[j];
			if(t==k && j>=last)
			{
				//cout<<j+1<<" "<<i<<endl;
				ans++;
				last=i;
			} 
		}
	}
	cout<<ans;
	return 0;
 }

