//GZ-S00124 贵阳市白云区华师一学校 姜裕伟 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
vector<long long> a1,a2,a3;
struct aaa
{
	long long v;
	long long id;
};
struct aa
{
	aaa a[4];
}a[100005];
long long t;
bool cmp(aaa a,aaa b)
{
	return a.v>b.v;
}
bool cmppp(aaa a,aaa b)
{
	return a.v<b.v;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		for(long long i=1;i<=100000;i++) 
		{
			for(long long j=1;j<=3;j++) 
			{
				a[i].a[j].v=0;
				a[i].a[j].id=0;
			}
		} 
		ans=0;
		a1.clear();
		a2.clear();
		a3.clear();
		scanf("%d",&n);
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=3;j++) scanf("%d",&a[i].a[j].v),a[i].a[j].id=j;
			sort(a[i].a+1,a[i].a+1+3,cmp);
		}
		for(long long i=1;i<=n;i++)
		{
			if(a[i].a[1].id==1)
			{
				a1.push_back(i);	
				ans+=a[i].a[1].v;
			}
			else if(a[i].a[1].id==2)
			{
				a2.push_back(i);
				ans+=a[i].a[1].v;
			}
			else
			{
				a3.push_back(i);
				ans+=a[i].a[1].v;
			}
		}
		if(a1.size()>n/2)
		{
			vector<aaa> ab;
			ab.clear();
			for(long long i=0;i<a1.size();i++)
			{
				ab.push_back({a[a1[i]].a[1].v-a[a1[i]].a[2].v,a1[i]});
			}
			sort(ab.begin(),ab.end(),cmppp);
			for(long long i=0;i<a1.size()-n/2;i++)
			{
				ans-=ab[i].v;
			}
		}
		else if(a2.size()>n/2)
		{
			vector<aaa> ab;
			ab.clear();
			for(long long i=0;i<a2.size();i++)
			{
				ab.push_back({a[a2[i]].a[1].v-a[a2[i]].a[2].v,a2[i]});
			}
			sort(ab.begin(),ab.end(),cmppp);
			for(long long i=0;i<a2.size()-n/2;i++)
			{
				ans-=ab[i].v;
			}
		}
		else if(a3.size()>n/2)
		{
			vector<aaa> ab;
			ab.clear();
			for(long long i=0;i<a3.size();i++)
			{
				ab.push_back({a[a3[i]].a[1].v-a[a3[i]].a[2].v,a3[i]});
			}
			sort(ab.begin(),ab.end(),cmppp);
			for(long long i=0;i<a3.size()-n/2;i++)
			{
				ans-=ab[i].v;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
