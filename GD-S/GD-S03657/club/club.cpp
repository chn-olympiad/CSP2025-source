#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
vector<pair<int,int> > a;
vector<pair<int,int> > b;
vector<pair<int,int> > c;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,team;
	cin>>t;
	for(team=0;team<t;team++)
	{
		
		int n,i,x,y,z;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x>>y>>z;
			a.push_back({x,i});
			b.push_back({y,i});
			c.push_back({z,i});
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		vector<bool> count(n,0);
		x=n-1;
		y=n-1;
		z=n-1;
		int xj=0,yj=0,zj=0;
		int sum=0,f=0;
		a.push_back({-1,n+1});
		b.push_back({-1,n+1});
		c.push_back({-1,n+1});
		for(i=0;i<n;i++)
		{
			if(xj>n/2)
			{
				x=n;
			}
			if(yj>n/2)
			{
				y=n;
			}
			if(zj>n/2)
			{
				z=n;
			}
			if(x<=0)
			{
				x=0;
			}
			if(y<=0)
			{
				y=0;
			}
			if(z<=0)
			{
				z=0;
			}
			f=0;
			while(f==0)
			{
				if((a[x].first>=b[y].first)||(a[x].first>=c[z].first))
				{
					if(a[x].first>=c[z].first)
					{
						if(a[x].first>=b[y].first)
						{
							if(count[a[x].second]==0){
								count[a[x].second]=1;f=a[x].first;xj++;
							}
							else x--;
						}
						else
						{
							if(count[b[y].second]==0) {
								count[b[y].second]=1;f=b[y].first;yj++;
							}
							else y--;
						}
					}
					else
					{
						if(count[c[z].second]==0){
							count[c[z].second]=1;f=c[z].first;zj++;
						}
						else z--;
					}
				}
				else
				{
					if((b[y].first>=a[x].first)||(b[y].first>=c[z].first))
					{
						if(b[y].first>=c[z].first)
						{
							if(b[y].first>=a[x].first)
							{
								if(count[b[y].second]==0){
									count[b[y].second]=1;f=b[y].first;yj++;
								}
								else y--;
							}
							else
							{
								if(count[a[x].second]==0){
									count[a[x].second]=1;f=a[x].first;xj++;
								}
								else x--;
							}
						}
						else
						{
							if(count[c[z].second]==0){
								count[c[z].second]=1;f=c[z].first;zj++;
							}
							else z--;
						}
					}
					else
					{
						if(c[z].first>=a[x].first)
						{
							if(c[z].first>=a[x].first)
							{
								if(count[c[z].second]==0){
									count[c[z].second]=1;f=c[z].first;zj++;
								}
								else z--;
							}
							else
							{
								if(count[a[x].second]==0){
									count[a[x].second]=1;f=a[x].first;xj++;
								}
								else x--;
							}
						}
						else
						{
							if(count[b[y].second]==0){
								count[b[y].second]=1;f=b[y].first;yj++;
							}
							else y--;
						}
					}
				}
			}
			sum=sum+f;	
		}
		cout<<sum<<endl;
		a.clear();
		b.clear();
		c.clear();
		count.clear();
	}
}

