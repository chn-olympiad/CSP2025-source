#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long x,y,z;
}a[100005];
long long b[5];
bool cmp(node x,node y)
{
	return max(x.x,max(x.y,x.z))>max(y.x,max(y.y,y.z));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n;
	cin>>t;
	long long mx,mxx,mxxx,j,k,ans;
	while(t--)
	{
		cin>>n;
		for(long long i = 1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp);
		ans = 0;
		for(long long i = 1;i<=n;i++)
		{
			mx = mxx = mxxx = b[1] = b[2] = b[3] = 0;
			mx = max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x == mx)
			{
				j = 1;
				mxx = max(a[i].y,a[i].z);
				if(mxx == a[i].y)
				{
					k = 2;
				}
				else
				{
					k = 3;
				}
				mxxx = min(a[i].y,a[i].z);
			}
			if(a[i].y == mx)
			{
				j = 2;
				mxx = max(a[i].x,a[i].z);
				if(mxx == a[i].x)
				{
					k = 1;
				}
				else
				{
					k = 3;
				}
				mxxx = min(a[i].x,a[i].z);
			}
			if(a[i].z == mx)
			{
				j = 3;
				mxx = max(a[i].y,a[i].x);
				if(mxx == a[i].y)
				{
					k = 2;
				}
				else
				{
					k = 1;
				}
				mxxx = min(a[i].y,a[i].x);
			}
			if(b[j]<=n/2)
			{
				ans+=mx;
			}
			else if(b[k]<=n/2)
			{
				ans+=mxx;
			}
			else
			{
				ans+=mxxx;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
