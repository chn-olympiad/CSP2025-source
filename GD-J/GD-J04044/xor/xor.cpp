#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5,K=2e6;//K=pow(2,20)
int n,k;
int a[N];
int sum[N];
int mn[N];
int f[N];
vector<int> num[K];
int mx[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],sum[i]=sum[i-1]^a[i];
		num[sum[i]].push_back(i);
	}
	
	for(int l=1;l<=n;l++)
	{
		int t=sum[l-1]^k,len=num[t].size();
		if(len==0||num[t][len-1]<l)
		{
			mn[l]=N;
			continue;
		}
		
		mn[l]=num[t][lower_bound(num[t].begin(),num[t].end(),l)-num[t].begin()];
//		for(int r=l;r<=n;r++)
//			if((sum[r]^sum[l-1])==k)
//				{mn[l]=r;break;}
	}
		
	
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		mx[i]=mx[i+1];
		if(mn[i]==N) continue;
		
		f[i]=mx[mn[i]+1]+1;
		
		ans=max(ans,f[i]);
		mx[i]=max(mx[i],f[i]);
	}
	
	cout<<ans;

	return 0;
}
/*
985 55
*/
