#include<bits/stdc++.h>
using namespace std;
long long t,a[110110][4],n,a1,b1,c1,ans;
struct xing{
	long long z;
};
bool operator < (xing a,xing b)
{
	return a.z>b.z;
}
priority_queue<xing> a2,b2,c2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		b1=0;
		c1=0;
		a1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
			    cin>>a[i][j];
		    }
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				{
					if(a1>=n/2)
					{
						if(!a2.empty()&&a2.top().z<a[i][1]-max(a[i][2],a[i][3]))
						{
						    ans-=a2.top().z;
						    a2.pop();
						     ans+=a[i][1];
						     a2.push({a[i][1]-max(a[i][2],a[i][3])});
					    }else
					    {
					    	ans+=max(a[i][2],a[i][3]);
						}
					}else
					{
					    ans+=a[i][1];
					    a2.push({a[i][1]-max(a[i][2],a[i][3])});
					    a1++;
					}
				}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				{
				//	cout<<"jin"<<2<<" "<<b1<<" "<<b2.size()<<endl; 
						if(b1>=n/2)
					{
						if(!b2.empty()&&b2.top().z<a[i][2]-max(a[i][1],a[i][3]))
						{
							//cout<<"fas"<<endl; 
						    ans-=b2.top().z;
						    b2.pop();
						     ans+=a[i][2];
						     b2.push({a[i][2]-max(a[i][1],a[i][3])});
					    }else
					    {
					    	ans+=max(a[i][1],a[i][3]);
						}
					}else
					{
						//cout<<"zhi"<<endl; 
					    ans+=a[i][2];
					    b2.push({a[i][2]-max(a[i][1],a[i][3])});
					    b1++;
					}
				//	cout<<b2.size()<<endl; 
				}else
				{
					if(c1>=n/2)
					{
						if(!c2.empty()&&c2.top().z<a[i][3]-max(a[i][1],a[i][2]))
						{
						    ans-=c2.top().z;
						    	c2.pop();
						     ans+=a[i][3];
						     c2.push({a[i][3]-max(a[i][1],a[i][2])});
					    }else
					    {
					    	ans+=max(a[i][1],a[i][2]);
						}
					}else
					{
					    ans+=a[i][3];
					    c2.push({a[i][3]-max(a[i][1],a[i][2])});
					    c1++;
					}
			}
		}
		cout<<ans<<endl;
		while(!a2.empty()) 
		{
			a2.pop();
		}
		while(!b2.empty()) 
		{
			b2.pop();
		}
		while(!c2.empty()) 
		{
			c2.pop();
		}
	}
}
