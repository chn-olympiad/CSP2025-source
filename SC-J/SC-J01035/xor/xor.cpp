#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum[500005],ans=0;
vector<int>eg[1000005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		sum[i]=sum[i-1]^a;
		eg[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;)
	{
		if(!eg[k].size()) 
		{
			k^=(sum[i]^sum[i-1]);
			i++;
			continue;
		}
		int l=0,r=eg[k].size()-1,cnt=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(eg[k][mid]>=i) r=mid-1,cnt=mid;
			else l=mid+1;
		}
		if(cnt!=-1)
		{
			ans++;
			int j=i;
			i=eg[k][cnt]+1;
			k^=(sum[eg[k][cnt]]^sum[j-1]);
		}
		else k^=(sum[i]^sum[i-1]),i++;
	}
	cout<<ans;
	return 0;
}