//GZ-S00498 贵阳市第十八中学 高逸晨 
#include<bits/stdc++.h>
using namespace std;
int t,n,g,cnt,a[100005],b[100005],c[100005],d[100005],e[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		priority_queue<int>a1;
		priority_queue<int>b1;
		priority_queue<int>c1;		
		scanf("%d",&n);
		g=n>>1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			scanf("%d",&b[i]);
			scanf("%d",&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				d[i]=a[i],e[i]=a[i]-max(b[i],c[i]);
				a1.push(-e[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				d[i]=b[i],e[i]=b[i]-max(a[i],c[i]);
				b1.push(-e[i]);
			}	
			else
			{
				d[i]=c[i],e[i]=c[i]-max(b[i],a[i]);
				c1.push(-e[i]);
			} 
			cnt+=d[i];
		}
		while(a1.size()>g)
		{
			cnt+=a1.top();
			a1.pop();
		}
		while(b1.size()>g)
		{
			cnt+=b1.top();
			b1.pop();
		}
		while(c1.size()>g)
		{
			cnt+=c1.top();
			c1.pop();
		}
		printf("%lld\n",cnt);
		cnt=0;
	}
	return 0;
}
