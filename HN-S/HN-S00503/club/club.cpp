#include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct man
{
	int id,sa1,sa2,maxn,minn;
};
bool cmp(man x,man y)
{
	if(x.maxn!=y.maxn)return x.maxn<y.maxn;
	return x.minn<y.minn;	
}
void as(int o)
{
	man a[100005];
	for(int i=1;i<=n;i++)
	{
		int s1,s2,s3;
		cin>>s1>>s2>>s3;
		a[i].id=i;
		a[i].maxn=max(s1,s2);
		a[i].minn=min(s2,s1);
		if(a[i].maxn==s1)
		{
			a[i].sa1=1;
			a[i].sa2=2;
		}
		else
		{
			a[i].sa1=2;
			a[i].sa2=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	int cnt[3]={0,0,0};
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i].sa1]<n/2)
		{
			sum+=a[i].maxn;
			cnt[a[i].sa1]++;
		}
		else
		{
			sum+=a[i].minn;
			cnt[a[i].sa2]++;
		}
	}
	cout<<sum;
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		as(0);
	}
	return 0;
}
