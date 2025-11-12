#include<bits/stdc++.h>
using namespace std;
struct xxs
{
	int n,bh;
};
xxs a[100005];
xxs b[100005];
xxs c[100005];
bool vis[100005];
bool cmp(xxs x,xxs y)
{
	return x.n>y.n;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long ans=0;
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i].n>>b[i].n>>c[i].n;
			vis[i]=0;
			a[i].bh=i;
			b[i].bh=i;
			c[i].bh=i;
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		int ar=0,br=0,cr=0;
		for(int i=0;i<n;i++)
		{
			
				int bj=a[i].bh; 
				if(vis[bj]==0&&ar<n/2)
				{
					ar++;
					vis[bj]=1;
					ans+=a[i].n;
				}
				bj=b[i].bh; 
				if(vis[bj]==0&&br<n/2)
				{
					br++;
					vis[bj]=1;
					ans+=b[i].n;
				}
				bj=c[i].bh; 
				if(vis[bj]==0&&cr<n/2)
				{
					cr++;
					vis[bj]=1;
					ans+=c[i].n;
				}
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
