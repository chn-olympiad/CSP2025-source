#include<bits/stdc++.h>
using namespace std;
int t,n,b[3],num,ans;
struct node
{
	pair<int,int> li[3];
} a[100005];
bool operator<(node x,node y)
{
	bool k1=0,k2=0;
	if (x.li[2].second==num)
	k1=1;
	if (y.li[2].second==num)
	k2=1;
	if (k1==k2)
	return x.li[2].first-x.li[1].first<y.li[2].first-y.li[1].first;
	else
	return k1>k2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			for (int j=0;j<3;++j)
			{
				a[i].li[j].second=j;
				scanf("%d",&a[i].li[j].first);
			}
			sort(a[i].li,a[i].li+3);
		}
		ans=0;
		for (int i=0;i<3;++i)
		b[i]=0;
		for (int i=1;i<=n;++i)
		{
			ans+=a[i].li[2].first;
			++b[a[i].li[2].second];
		}
		num=-1;
		for (int i=0;i<3;++i)
		if (2*b[i]>n)
		{
			num=i;
			break;
		}
		if (num!=-1)
		{
			sort(a+1,a+n+1);
			for (int i=1;i<=b[num]-n/2;++i)
			ans-=a[i].li[2].first-a[i].li[1].first;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
