#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int t,n,ans,sum[5],idx,idy,idz,x,y,z;
int rec[100005];
priority_queue<pair<int,int> > q[5];
struct stu
{
	int x,y,z,idx,idy,idz;
}a[100005];
void rd()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		idx=1;
		idy=2;
		idz=3;
		bool flag=1;
		while(flag)
		{
			if(y>x)
			{
				swap(x,y);
				swap(idx,idy);
			}
			if(z>y)
			{
				swap(y,z);
				swap(idy,idz);
			}
			if(x>y&&y>z) flag=0;
		}
		a[i].x=x;
		a[i].y=y;
		a[i].z=z;
		a[i].idx=idx;
		a[i].idy=idy;
		a[i].idz=idz;
	}
}
void turn(int i)
{
	if(rec[i]==1)
	{
		if(sum[a[i].idy]<n/2)
		{
			sum[a[i].idy]++;
			q[a[i].idy].push({a[i].z-a[i].y,i});
			rec[i]=2;
		}
		else if(q[a[i].idy].top().first+a[i].y>0)
		{
			ans+=q[a[i].idy].top().first+a[i].y;
			rec[i]=2;
			turn(q[a[i].idy].top().second);
			q[a[i].idy].pop();
			q[a[i].idy].push({a[i].z-a[i].y,i});
		}
	}
	else if(rec[i]==2)
	{
		sum[a[i].idz]++;
		rec[i]=3;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=3;i++)
		{
			if(!q[i].empty()) q[i].pop();
		}
		memset(rec,0,sizeof(rec));
		rd();
		for(int i=1;i<=n;i++)
		{
			if(sum[a[i].idx]<n/2)
			{
				sum[a[i].idx]++;
				ans+=a[i].x;
				q[a[i].idx].push({a[i].y-a[i].x,i});
				rec[i]=1;
			}
			else if(q[a[i].idx].top().first+a[i].x>0)
			{
				ans+=(q[a[i].idx].top().first+a[i].x);
				rec[i]=1;
				turn(q[a[i].idx].top().second);
				q[a[i].idx].pop();
				q[a[i].idx].push({a[i].y-a[i].x,i});
			}
			else if(sum[a[i].idy]<n/2)
			{
				sum[a[i].idy]++;
				ans+=a[i].y;
				q[a[i].idy].push({a[i].z-a[i].y,i});
				rec[i]=2;
			}
			else if(q[a[i].idy].top().first+a[i].y>0)
			{
				ans+=q[a[i].idy].top().first+a[i].y;
				rec[i]=2;
				turn(q[a[i].idy].top().second);
				q[a[i].idy].pop();
				q[a[i].idy].push({a[i].z-a[i].y,i});
			}
			else
			{
				ans+=a[i].z;
				sum[a[i].idz]++;
				rec[i]=3;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
