#include<bits/stdc++.h>
using namespace std;
long long a[1005],x[1005][1005];
pair<long long,long long> p[1000005];
long long n,k,ans=0,cnt=0,tmp=0;
//void dfs(int cnt,int sum,int id)
//{
//	if(sum==k)
//	{
//		ans++;
//	}
//	else
//	{
//		for(int i=id;i<=n;i++)
//		{
//			if(sum+x[id][i]<=k)
//			{
//				for(int j=i+1;j<=n;j++)
//				{
//					dfs(cnt+1,sum^x[id][i],j);
//				}
//			}
//		}
//	}
//}
bool cmp(pair<long long,long long> p1,pair<long long,long long> p2)
{
	if(p1.first!=p2.first)
	return p1.first<p2.first;
	else
	return p1.second<p2.second;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=0;i+l<=n;l++)
		{
			long long j=i+l;
			if(l==0)
			{
				x[i][j]=a[i];
			}
			else
			{
				x[i][j]=x[i][j-1]^a[j];
			}
			if(x[i][j]==k)
			{
				p[++cnt]={i,j};
				tmp=1;
			}
		}
	}
	long long maxx=0;
	sort(p+1,p+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		ans=tmp;
		long long lst=p[i].second;
		for(int j=i+1;j<=cnt;j++)
		{
			if(p[j].first>lst)
			{
				ans++;
				lst=p[j].second;
			}
		}
		maxx=max(maxx,ans);
	}
	
	cout<<maxx;
//	dfs(0,0,1);
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}