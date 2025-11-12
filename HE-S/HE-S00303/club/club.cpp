#include<bits/stdc++.h>
using namespace std;
struct abc
{
	int x,y,z;
}a;
multimap<int,abc>m1,m2,m3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a.x,&a.y,&a.z);
			int maxn=max(max(a.x,a.y),a.z);
			if(a.x==maxn)     m1.insert(make_pair(a.x-max(a.y,a.z),a)),sum+=a.x;
			else if(a.y==maxn)m2.insert(make_pair(a.y-max(a.x,a.z),a)),sum+=a.y;
			else              m3.insert(make_pair(a.z-max(a.x,a.y),a)),sum+=a.z;
		}
		int l1=m1.size(),l2=m2.size(),l3=m3.size(),k=n/2;
		abc c;
		if(l1>k || l2>k || l3>k)
		{
			if(l1>k) while(l1>k)
			{
				c=m1.begin()->second;
				if(c.y>c.z)sum+=c.y-c.x;
				else       sum+=c.z-c.x;
				m1.erase(m1.begin());
				l1--;
			}
			else if(l2>k) while(l2>k)
			{
				c=m2.begin()->second;
				if(c.x>c.z)sum+=c.x-c.y;
				else       sum+=c.z-c.y;
				m2.erase(m2.begin());
				l2--;
			}
			else while(l3>k)
			{
				c=m3.begin()->second;
				if(c.x>c.y)sum+=c.x-c.z;
				else       sum+=c.y-c.z;
				m3.erase(m3.begin());
				l3--;
			}
		}
		printf("%d\n",sum);
		m1.clear();m2.clear();m3.clear();
	}
}
