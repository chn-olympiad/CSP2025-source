#include<bits\stdc++.h>
#define int long long
using namespace std;
int t,n,a[200005][3];
priority_queue<int,vector<int>,greater<int> > p1,p2,p3;
signed main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int x=0,y=0,z=0;
		int ans=0;
		while(p1.size()) p1.pop();
		while(p2.size()) p2.pop();
		while(p3.size()) p3.pop();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
			{
				x++;
				ans+=a[i][0];
				if(x<=n/2)
					p1.push(a[i][0]-max(a[i][1],a[i][2]));
				else
				{
					p1.push(a[i][0]-max(a[i][1],a[i][2]));
					int v=p1.top();
					p1.pop();
					x--;
					ans-=v;
				}
			}
			else if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][0])
			{
				y++;
				ans+=a[i][1];
				if(y<=n/2)
					p2.push(a[i][1]-max(a[i][0],a[i][2]));
				else
				{
					p2.push(a[i][1]-max(a[i][0],a[i][2]));
					int v=p2.top();
					p2.pop();
					y--;
					ans-=v;
				}
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0])
			{
				z++;
				ans+=a[i][2];
				if(z<=n/2)
					p3.push(a[i][2]-max(a[i][1],a[i][0]));
				else
				{
					p3.push(a[i][2]-max(a[i][1],a[i][0]));
					int v=p3.top();
					p3.pop();
					z--;
					ans-=v;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
