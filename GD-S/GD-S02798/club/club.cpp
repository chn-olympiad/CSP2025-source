#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans;
struct node
{int x,y,z;}a[N];
vector<int>ax,ay,az;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		ax.clear();ay.clear();az.clear();
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>=max(a[i].y,a[i].z))
			{
				ans+=a[i].x;
				ax.push_back(abs(a[i].x-max(a[i].y,a[i].z)));
				continue;
			}
			if(a[i].y>=max(a[i].x,a[i].z))
			{
				ans+=a[i].y;
				ay.push_back(abs(a[i].y-max(a[i].x,a[i].z)));
				continue;
			}
			if(a[i].z>=max(a[i].x,a[i].y))
			{
				ans+=a[i].z;
				az.push_back(abs(a[i].z-max(a[i].x,a[i].y)));
				continue;
			}
		}
		if(ax.size()<=n/2)
		if(ay.size()<=n/2)
		if(az.size()<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		sort(ax.begin(),ax.end());
		sort(ay.begin(),ay.end());
		sort(az.begin(),az.end());
		if(ax.size()>n/2)
			for(int i=0;i<ax.size()-n/2;i++)
				ans-=ax[i];
		if(ay.size()>n/2)
			for(int i=0;i<ay.size()-n/2;i++)
				ans-=ay[i];
		if(az.size()>n/2)
			for(int i=0;i<az.size()-n/2;i++)
				ans-=az[i];
		cout<<ans<<endl;
	}
	return 0;
}
