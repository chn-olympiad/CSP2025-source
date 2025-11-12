#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		int n;
		cin>>n;
		int a[n+1][4],sum=0,b=0,c=0,d=0,e[n+1],f[n+1],g[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			sum+=max(a[i][1],max(a[i][2],a[i][3]));
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
				b++;
				e[i]=a[i][1];
			}
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]){
				c++;
				f[i]=a[i][2];
			}
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3]){
				d++;
				g[i]=a[i][3];
			
			} 
		}
		while(b>n/2)
		{
			int minn=1938219,k;
			for(int i=1;i<=n;i++)
			{
				minn=min(minn,e[i]); 
				if(e[i]<=minn)
					k=i;
			}
			sum-=minn;
			int maxn=-13879221;
			minn=96231481;
			maxn=max(a[k][1],max(a[k][2],a[k][3]));
			minn=min(a[k][1],min(a[k][2],a[k][3]));
			if(a[k][1]!=maxn&&a[k][1]!=minn)
			{
				sum+=a[k][1];
			}
			if(a[k][2]!=maxn&&a[k][2]!=minn)
			{
				sum+=a[k][2];
			}
			if(a[k][3]!=maxn&&a[k][3]!=minn)
			{
				sum+=a[k][3];
			}
			b-=1;
		}
		while(c>n/2)
		{
			int minn=1938219,k;
			for(int i=1;i<=n;i++)
			{
				minn=min(minn,e[i]); 
				if(f[i]<=minn)
					k=i;
			}
			sum-=minn;
			int maxn=-13879221;
			minn=96231481;
			maxn=max(a[k][1],max(a[k][2],a[k][3]));
			minn=min(a[k][1],min(a[k][2],a[k][3]));
			if(a[k][1]!=maxn&&a[k][1]!=minn)
			{
				sum+=a[k][1];
			}
			if(a[k][2]!=maxn&&a[k][2]!=minn)
			{
				sum+=a[k][2];
			}
			if(a[k][3]!=maxn&&a[k][3]!=minn)
			{
				sum+=a[k][3];
			}
			c-=1;
		}
		while(d>n/2)
		{
			int minn=1938219,k;
			for(int i=1;i<=n;i++)
			{
				minn=min(minn,e[i]); 
				if(g[i]<=minn)
					k=i;
			}
			sum-=minn;
			int maxn=-13879221;
			minn=96231481;
			maxn=max(a[k][1],max(a[k][2],a[k][3]));
			minn=min(a[k][1],min(a[k][2],a[k][3]));
			if(a[k][1]!=maxn&&a[k][1]!=minn)
			{
				sum+=a[k][1];
			}
			if(a[k][2]!=maxn&&a[k][2]!=minn)
			{
				sum+=a[k][2];
			}
			if(a[k][3]!=maxn&&a[k][3]!=minn)
			{
				sum+=a[k][3];
			}
			d-=1;
		}
		cout<<sum<<endl;
	}
}
