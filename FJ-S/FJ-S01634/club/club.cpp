
#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];

struct edge{
	int x,y,z;
	int id;
};

bool cmp(edge l,edge r)
{
	return (l.x+l.y)<(r.x+r.y);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		cin>>n;
		bool x=0,y=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			//cout<<a[i]<<endl;
			if(b[i]!=0||c[i]!=0)
				x=1;
			if(c[i]!=0)
				y=1;
		}
		if(!x)
		{
			sort(a+1,a+n+1);
			//for(int i=1;i<=n;i++)
			//	cout<<a[i]<<" ";
			//cout<<endl;	
			for(int i=0;i<n/2;i++)
				ans+=a[n-i];
		}
		else
		{
			
			if(!y)
			{
				edge q[n+1];
				int l=0,r=0,s=n;
				s/=2;
				for(int i=1;i<=n;i++)
				{
					q[i].x=a[i];
					q[i].y=b[i];
					q[i].id=i;
				}
				sort(q+1,q+n+1,cmp);
				for(int i=1;i<=n;i++)
				{
					//cout<<q[i].x<<" "<<q[i].y<<endl;
					if(q[i].x>q[i].y)
					{
						if(l<s)
						{
							ans+=q[i].x;
							//cout<<ans<<endl;
							l++;
						}
						else
						{
							ans+=q[i].y;
							//cout<<ans<<endl;
							r++;
						}
					}
					if(q[i].x<q[i].y)
					{
						if(r<s)
						{
							ans+=q[i].y;
							//cout<<ans<<endl;
							r++;
						}
						else
						{
							ans+=q[i].x;
							//cout<<ans<<endl;
							l++;
						}
					}
					if(q[i].x==q[i].y)
					{
						if(l==s)
						{
							ans+=q[i].y;
							//cout<<ans<<endl;
							r++;
						}
						else
						{
							if(r==s)
							{
								ans+=q[i].x;
								//cout<<ans<<endl;
								l++;
							}
							else
							{
								if(q[i+1].x<q[i+1].y)
								{
									ans+=q[i].x;
									//cout<<ans<<endl;
									l++;
								}
								else
								{
									ans+=q[i].y;
									//cout<<ans<<endl;
									r++;
								}
							}
						}
						
					}
				}
			}
			else
			{
				for(int i=1;i<=n;i++)
				{
					int maxx=max(a[i],b[i]);
					maxx=max(maxx,c[i]);
					ans+=maxx;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}



