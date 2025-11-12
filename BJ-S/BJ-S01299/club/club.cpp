#include<bits/stdc++.h>
using namespace std;
int a[200010][5];
int b[200010];
int c[200010];
int d[200010];
int e[200010];
int vis[200010];
int k=0;
int main()
{
		freopen("club.in","in",stdin);
	freopen("club.out","out",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }		//cout<<1;
        if(a[1][2]==0&&a[1][3]==0)
        {
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			int ans=0;
			for(int i=n;i>=n/2+1;i--)
			{
				ans+=b[i];
			}
			cout<<ans<<endl;
			return 0;
		}
		if(a[1][3]==0&&a[2][3]==0&&a[3][3]==0)
		{
			
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1];
				c[b[i]]=i;
			}
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++)
			{
				vis[c[b[n-i+1]]]=1;
				ans+=b[i];
				for(int j=1;j<=n;j++)
				{
					if(vis[i]==0)
					{
						ans+=a[i][2];
					}
				}
			}
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i][1];
			c[a[i][1]]=i;
			d[i]=a[i][2];
			e[a[i][2]]=i;
		}
		sort(d+1,d+n+1);
		sort(b+1,b+n+1);
        for(int i=1;i<=n/2;i++)
        {
			vis[c[b[n-i+1]]]=1;
			ans+=b[n-i+1];
			//cout<<ans;
			for(int j=1;j<=n/2;j++)
			{
				int cc=j;
				for(int u=1;u<=cc;u++)
				{
					while(vis[e[d[n-cc+1]]]==1)
					{
						cc++;
					}
					vis[e[d[n-cc+1]]]=1;
					ans+=d[n-cc+1];
					for(int q=1;q<=n;q++)
					{
						if(vis[q]==0)
						{
							ans+=a[q][3];
						}
					}
				}
				k=n-i-j;
			}
		}
    }
    return 0;
}
