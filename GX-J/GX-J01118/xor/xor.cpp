#include<bits/stdc++.h>
using namespace std;
int n,k,len,ans,a[500005];
vector<pair<int,int> > v;
bool cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second!=y.second?x.second<y.second:x.first<y.first;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k)
			{
				v.push_back({i,j}),len++;
				break;
			}
		}
	}
	if(len==0)
	{
		puts("0");
		return 0;
	}
	stable_sort(v.begin(),v.end(),cmp);
	int r=v[0].second;
	ans=1;
	for(int i=1;i<len;i++)
		if(r<v[i].first)
			ans++,r=v[i].second;
	printf("%d",ans);
	return 0;
}
