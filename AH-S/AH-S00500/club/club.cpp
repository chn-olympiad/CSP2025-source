#include<bits/stdc++.h>
using namespace std;
int t,n,f[5],ans;
struct node 
{
	int x,y,z;
}a[1000000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(f,0,sizeof(f));
		cin>>n;
		priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>=a[i].y && a[i].x>=a[i].z)
			{
				ans+=a[i].x;
				q1.push(min(a[i].x-a[i].y,a[i].x-a[i].z));
				f[1]++;
				if(f[1]>n/2)
				{
					ans-=q1.top();
					q1.pop();
					f[1]--;
				}
			}
			else if(a[i].y>=a[i].x && a[i].y>=a[i].z)
			{
				ans+=a[i].y;
				q2.push(min(a[i].y-a[i].x,a[i].y-a[i].z));
				f[2]++;
				if(f[2]>n/2)
				{
					ans-=q2.top();
					q2.pop();
					f[2]--;
				}
			}
			else if(a[i].z>=a[i].y && a[i].z>=a[i].x)
			{
				ans+=a[i].z;
				q3.push(min(a[i].z-a[i].y,a[i].z-a[i].x));
				f[3]++;
				if(f[3]>n/2)
				{
					ans-=q3.top();
					q3.pop();
					f[3]--;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
