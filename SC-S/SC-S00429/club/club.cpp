#include<bits/stdc++.h>
using namespace std;
int T,n,maxx=-1;
int cnt[5],c[5],a[100050][5];
long long ans=0;
struct node{
	int s,id;
};
node m1[100050],m2[100050],m3[100050];
bool cmp(node a,node b)
{
	return a.s<b.s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=3;++i)
		{
			cnt[i]=0;
			c[i]=0;
		}
		for(int i=1;i<=n;++i)
		{
			m1[i].id=0,m1[i].s=0;
			m2[i].id=0,m2[i].s=0;
			m3[i].id=0,m3[i].s=0;
			
		}
		for(int i=1;i<=n;++i)
		{
			maxx=-1;
			int idx;
			for(int j=1;j<=3;++j)
			{
				scanf("%d",&a[i][j]);
				if(maxx<a[i][j])
				{
					idx=j;
					maxx=a[i][j];
				}
			}
			if(idx==1)
			{
				m1[i].s=maxx;
				m1[i].id=1;
				cnt[1]++;
				if(a[i][2]>=a[i][3])
				{
					m2[i].s=a[i][2];
					m2[i].id=2;
					m3[i].s=a[i][3];
					m3[i].id=3;
				}
				else if(a[i][2]<a[i][3])
				{
					m2[i].s=a[i][3];
					m2[i].id=3;
					m3[i].s=a[i][2];
					m3[i].id=2;
				}
			}
			else if(idx==2)
			{
				m1[i].s=maxx;
				m1[i].id=2;
				cnt[2]++;
				if(a[i][1]>=a[i][3])
				{
					m2[i].s=a[i][1];
					m2[i].id=1;
					m3[i].s=a[i][3];
					m3[i].id=3;
				}
				else if(a[i][1]<a[i][3])
				{
					m2[i].s=a[i][3];
					m2[i].id=3;
					m3[i].s=a[i][1];
					m3[i].id=1;
				}
			}
			else if(idx==3)
			{
				m1[i].s=maxx;
				m1[i].id=3;
				cnt[3]++;
				if(a[i][2]>=a[i][1])
				{
					m2[i].s=a[i][2];
					m2[i].id=2;
					m3[i].s=a[i][1];
					m3[i].id=1;
				}
				else if(a[i][2]<a[i][1])
				{
					m2[i].s=a[i][1];
					m2[i].id=1;
					m3[i].s=a[i][2];
					m3[i].id=2;
				}
			}
		}
		int m=n/2;
		bool f=1;
		for(int i=1;i<=3;++i)
		{
			if(cnt[i]>m)
			{
				f=0;
				break;
			}
		}
		if(f==1)
		{
			for(int i=1;i<=n;++i)
				ans+=m1[i].s;
		}
		else
		{
			sort(m1+1,m1+n+1,cmp);
			sort(m2+1,m2+n+1,cmp);
			sort(m3+1,m3+n+1,cmp);
			for(int i=1;i<=3;++i)	c[i]=cnt[i]-m;
			if(c[1]>0)
			{
				for(int i=1;i<=c[1];++i)
				{
					
					if(c[2]<m)
					{
						swap(m1[i].s,m2[i].s);
						swap(m1[i].id,m2[i].id);
						c[2]++;
					}
					else
					{
						swap(m1[i].s,m3[i].s);
						swap(m1[i].id,m3[i].id);
						c[3]++;
					}
				}
			}
			if(c[2]>0)
			{
				for(int i=1;i<=c[2];++i)
				{
					
					if(c[1]<m)
					{
						swap(m1[i].s,m2[i].s);
						swap(m1[i].id,m2[i].id);
						c[1]++;
					}
					else
					{
						swap(m2[i].s,m3[i].s);
						swap(m2[i].id,m3[i].id);
						c[3]++;
					}
				}
			}
			if(c[3]>0)
			{
				for(int i=1;i<=c[3];++i)
				{
					
					if(c[1]<m)
					{
						swap(m1[i].s,m3[i].s);
						swap(m1[i].id,m3[i].id);
						c[1]++;
					}
					else
					{
						swap(m2[i].s,m3[i].s);
						swap(m2[i].id,m3[i].id);
						c[2]++;
					}
				}
			}
			for(int i=1;i<=n;++i)
				ans+=m1[i].s;
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}