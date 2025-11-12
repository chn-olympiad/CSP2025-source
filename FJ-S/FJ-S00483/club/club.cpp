#include<bits/stdc++.h>
#define int long long
using namespace std; 
int t,n,f[2][110][110][110],ans;
struct Node
{
	int a,b,c,x,id;
}a[100010];
bool cmp(Node a,Node b)
{
	return a.a>b.a;
}
bool cmp2(Node a,Node b)
{
	return a.x<b.x;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(f,0,sizeof(f));
		ans=0;
		int flg=1,flg2=1; 
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c; 
			if(a[i].b!=0||a[i].c!=0)
			{
				flg=0;
			}
			if(a[i].c!=0)
			{
				flg2=0;
			}
		} 
		if(flg)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(flg2)
		{
			int num=0,num2=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].a>=a[i].b)
				{
					a[i].id=1;
					num++;
				}
				else
				{
					a[i].id=2;
					num2++;
				}
				ans+=max(a[i].a,a[i].b);
				a[i].x=abs(a[i].a-a[i].b);
			}
			if(num>n/2)
			{
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n;i++)
				{
					if(num==n/2)
					{
						break;
					}
					if(a[i].id==1)
					{
						ans-=a[i].x;
						num--;
						num2++;
					}
				}
			}
			else if(num2>n/2)
			{
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n;i++)
				{
					if(num2==n/2)
					{
						break;
					}
					if(a[i].id==2)
					{
						ans-=a[i].x;
						num2--;
						num++;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,n/2);j++)
			{
				for(int k=0;k<=min(i-j,n/2);k++)
				{	
					for(int h=0;h<=min(i-j-k,n/2);h++)
					{
						if(j>0)
						{
							f[i&1][j][k][h]=max(f[i&1][j][k][h],f[(i-1)&1][j-1][k][h]+a[i].a);
						}
						if(k>0)
						{
							f[i&1][j][k][h]=max(f[i&1][j][k][h],f[(i-1)&1][j][k-1][h]+a[i].b);
						}
						if(h>0)
						{
							f[i&1][j][k][h]=max(f[i&1][j][k][h],f[(i-1)&1][j][k][h-1]+a[i].c);
						}
					}
				}
			}
		}
		for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=min(n-i,n/2);j++)
			{	
				for(int k=0;k<=min(n-i-j,n/2);k++)
				{
					ans=max(ans,f[n&1][i][j][k]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
