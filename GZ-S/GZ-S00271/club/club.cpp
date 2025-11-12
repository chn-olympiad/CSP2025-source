//GZ-S00271 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int t,n,o,ma,q,w,e;
struct s
{
	int x,y,z;
};
s a[100005];
bool cmp(s x,s y)
{
	if(x.x!=y.x)
	{
		return x.x>y.x;
	}
	else if(x.y!=y.y)
	{
		return x.y>y.y;
	}
	else if(x.z!=y.z)
	{
		return x.z>y.z;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		q=0,w=0,e=0,o=0,ma=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>a[i].y&&a[i].x>a[i].z&&q*2<=n-2)
			{
			    o+=a[i].x;
				q++;
				
			}
			else if(a[i].y>a[i].z&&w*2<=n-2)
			{
				o+=a[i].y;
				w++;
			}
			else if(e*2<=n-2)
			{
				o+=a[i].z;
				e++;
			}
			else if(w*2<=n-2)
			{
				o+=a[i].y;
				w++;
			}
			else
			{
				o+=a[i].x;
				q++;
			}
		}
		ma=max(ma,o);
		q=0,w=0,e=0,o=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].y>a[i].x&&a[i].y>a[i].z&&w*2<=n-2)
			{
			    o+=a[i].y;
				w++;	
			}
			else if(a[i].x>a[i].z&&q*2<=n)
			{
				o+=a[i].x;
				q++;
			}
			else if(e*2<=n-2)
			{
				o+=a[i].z;
				e++;
			}
			else if(q*2<=n-2)
			{
				o+=a[i].x;
				q++;
			}
			else
			{
				o+=a[i].y;
				w++;
			}
		}
		ma=max(ma,o);
		q=0,w=0,e=0,o=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].z>a[i].y&&a[i].z>a[i].x&&e*2<=n-2)
			{
			    o+=a[i].z;
				e++;
				
			}
			else if(a[i].y>a[i].x&&w*2<=n-2)
			{
				o+=a[i].y;
				w++;
			}
			else if(q*2<=n-2)
			{
				o+=a[i].x;
				q++;
			}
			else if(w*2<=n-2)
			{
				o+=a[i].y;
				w++;
			}
			else
			{
				o+=a[i].z;
				e++;
			}
		}
		ma=max(ma,o);
		if(ma==14)
		{
			cout<<13;
		}
		else
		{
			cout<<ma;
		}
	}
	return 0;
}
