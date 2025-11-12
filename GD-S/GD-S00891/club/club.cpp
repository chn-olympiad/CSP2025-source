#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
long long t,n,ans;
long long a[110000][10];
vector<long long> v[10];
bool cmp(long long x,long long y) {return x>y;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld",&n);
		v[1].clear();
		v[2].clear();
		v[3].clear();
		for(int i=1;i<=n;i++)
		{
			long long a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			long long k=max(max(a,b),c);
			ans+=k;
			if(a==k) v[1].push_back(max(b,c)-a);
			if(b==k) v[2].push_back(max(a,c)-b);
			if(c==k) v[3].push_back(max(a,b)-c);
		}
		for(int i=1;i<=3;i++)
		{
			if(v[i].size()>n/2)
			{
				sort(v[i].begin(),v[i].end(),cmp);
				for(int j=0;j<v[i].size()-n/2;j++) ans+=v[i][j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
