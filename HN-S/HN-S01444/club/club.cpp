#include <bits/stdc++.h>
using namespace std;
struct chy
{
	int x[3],b,yr,ys,rs;
}a[100005];
bool cmp1(chy x,chy y)
{
	return min(x.yr,x.ys)<min(y.yr,y.ys); 
}
bool cmp2(chy x,chy y)
{
	return min(x.yr,x.rs)<min(y.yr,y.rs);
}
bool cmp3(chy x,chy y)
{
	return min(x.ys,x.rs)<min(y.ys,y.rs);
}
int n,s[5],su;
void solve()
{
	su=0;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
		a[i].yr=max(a[i].x[1],a[i].x[2])-min(a[i].x[1],a[i].x[2]);
		a[i].ys=max(a[i].x[1],a[i].x[3])-min(a[i].x[1],a[i].x[3]);
		a[i].rs=max(a[i].x[3],a[i].x[2])-min(a[i].x[3],a[i].x[2]);
		if(a[i].x[1]>=a[i].x[2]&&a[i].x[1]>=a[i].x[3])
		{
			s[1]++;
			su+=a[i].x[1];
			a[i].b=1;
		}
		else if(a[i].x[2]>=a[i].x[1]&&a[i].x[2]>=a[i].x[3])
		{
			s[2]++;
			su+=a[i].x[2];
			a[i].b=2;
		}
		else
		{
			s[3]++;
			su+=a[i].x[3];
			a[i].b=3;
		}
	}
	if(s[1]<=n/2&&s[2]<=n/2&&s[3]<=n/2)
	{
		cout<<su<<endl;
		return ;
	}
	if(s[1]>n/2)
	{
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
	    {
	    	int yr=a[i].yr,ys=a[i].ys,rs=a[i].rs;
	    	if(s[1]<=n/2)
	    	{
	    		break;
			}
    		if(a[i].b==1)
    		{
    			if(a[i].yr<a[i].ys)
    			{
				    if(s[2]<n/2)
				    {
    				    su-=yr;
    				    s[1]--;
    				    s[2]++;
					}
					else{
						su-=ys;
    				    s[1]--;
    				    s[3]++;
					}
				}
				else if(s[3]<n/2)
				{
					su-=ys;
					s[1]--;
					s[3]++;
				}
				else
				{
					su-=yr;
    				s[1]--;
    				s[2]++;
				}
    		}
    	}
	}
	else if(s[2]>n/2)
	{
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++)
	    {
	    	int yr=a[i].yr,ys=a[i].ys,rs=a[i].rs;
	    	if(s[2]<=n/2)
	    	{
	    		break;
			}
    		if(a[i].b==2)
    		{
    			if(a[i].yr<a[i].rs)
    			{
				    if(s[1]<n/2)
				    {
    				    su-=yr;
    				    s[2]--;
    				    s[1]++;
					}
					else{
						su-=rs;
    				    s[2]--;
    				    s[3]++;
					}
				}
				else if(s[3]<n/2)
				{
					su-=rs;
    				s[2]--;
    				s[3]++;
				}
				else
				{
					su-=yr;
    				s[2]--;
    				s[1]++;
				}
    		}
    	}
	}
	else if(s[3]>n/2)
	{
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++)
	    {
	    	int yr=a[i].yr,ys=a[i].ys,rs=a[i].rs;
	    	if(s[3]<=n/2)
	    	{
	    		break;
			}
    		if(a[i].b==3)
    		{
    			if(a[i].rs<a[i].ys)
    			{
				    if(s[2]<n/2)
				    {
    				    su-=rs;
    				    s[3]--;
    				    s[2]++;
					}
					else{
						su-=ys;
    				    s[3]--;
    				    s[1]++;
					}
				}
				else if(s[1]<n/2)
				{
					su-=ys;
					s[3]--;
					s[1]++;
				}
				else
				{
					su-=rs;
    				s[3]--;
    				s[2]++;
				}
    		}
    	}
	}
	cout<<su<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
