#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],ans,l,r;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){cout<<1;return 0;}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	l=1,r=n;
	int cna,cnb;
	while(l<r)
	{
		int mid=(l+r)/2;
		cna=a[l],cnb=a[r];
		for(int i=2;i<=mid;i++)if(cna<=k)cna^=a[i];
		for(int i=mid+1;i<n;i++)if(cnb<=k)cnb^=a[i];
		if(cna==cnb&&k>=cna&&k>=cnb)
		{
			ans=max(r-mid,mid-l);
			break;
		}
		else if(cna<cnb)
		{
			r=mid;
		}
		else l=mid;
		
	}
	cout<<ans;
}
