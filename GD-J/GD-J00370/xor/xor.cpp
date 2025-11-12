#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
int s[500011];
bool cmp(pair<int,int> x,pair<int,int> y)
{
	if(x.second!=y.second)
	return x.second<y.second;
	return x.first<y.first;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	bool p=1,f=1,q=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p&=(a[i]==1);
		f&=(a[i]<=1);
		q&=(a[i]<=255);
	}
	if(k==0&&p)
	{
		printf("%d",n/2);
		return 0;
	}
	if(!p&&f)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			ans++;
			else if(a[i-1]!=k&&k==0&&i>1)
			ans++,a[i]=k;
		}
		printf("%d",ans);
		return 0;
	}
	vector<pair<int,int>> ans;
	int cnt=0;
	for(int i=n;i>=1;i--)
	s[i]=s[i+1]^a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[i]^s[j+1])==k)
			{
				ans.push_back({i,j});
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	int start=-1;
	for(int i=0;i<(int)ans.size();i++)
	{
		if(ans[i].first>start)
		{
			start=ans[i].second;
			cnt++;
		}
	}
	printf("%d",cnt);
}

