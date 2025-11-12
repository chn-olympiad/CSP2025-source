#include<bits/stdc++.h>
using namespace std;
#define cin std::cin
#define cout std::cout
int t,n,a[100005][4],te[4],ans;
int l[4][100005];
int team[4][100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(te,0,sizeof(te));
		memset(team,0,sizeof(team));
		memset(l,0,sizeof(l));
		cin>>n;
		int top=n/2,op=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(!a[i][j]) op++;
		}
		if(n==2)
		{
			int maxn=-1;
			for(int i=1;i<=3;i++)
			for(int j=1;j<=3,j!=i;j++) 
				maxn=max(maxn,a[1][i]+a[2][j]);
			cout<<maxn<<endl;
			continue;
		}
		if(op>=n*2)
		{
			int opl[100005],ansx=0;
			for(int i=1;i<=n;i++) opl[i]=a[i][1];
			sort(opl+1,opl+n+1,cmp);
			for(int i=1;i<=top;i++) ansx+=opl[i];
			cout<<ansx<<endl;
			continue;
		}
  		for(int i=1;i<=n;i++)
		{
			int flag=1,maxn=-1;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>maxn)
				{
					flag=j;
					maxn=a[i][j];
				}
			}
			te[flag]++;
			l[flag][te[flag]]=maxn;
			team[flag][te[flag]]=i;
		}
		for(int i=1;i<=3;i++)
		{
			if(te[1]<=top&&te[2]<=top&&te[3]<=top) break;
			if(te[i]>top)
			{
				int op=te[i]-top;
				while(op--)
				{
					int minn=1e9,flag=1;
					for(int j=1;j<=te[i];j++)
					{
						if(l[i][j]<minn) 
						{
							flag=j;
							minn=l[i][j];
						}
					}
					int num=team[i][flag];
					if(i==1)
					{
						if(a[num][2]>=a[num][3])
						{
							te[1]--;
							te[2]++;
							l[2][te[2]]=a[num][2];
						}
						else
						{
							te[1]--;
							te[3]++;
							l[3][te[3]]=a[num][3];
						}
					}
					if(i==2)
					{
						if(a[num][1]>=a[num][3])
						{
							te[2]--;
							te[1]++;
							l[1][te[1]]=a[num][1];
						}
						else
						{
							te[2]--;
							te[3]++;
							l[3][te[3]]=a[num][3];
						}
					}
					else
					{
						if(a[num][2]>=a[num][1])
						{
							te[3]--;
							te[2]++;
							l[2][te[2]]=a[num][2];
						}
						else
						{
							te[3]--;
							te[1]++;
							l[1][te[1]]=a[num][1];
						}
					}
				}
			}
			else continue;
		}
		for(int i=1;i<=3;i++)
		for(int j=1;j<=te[i];j++)
			ans+=l[i][j];
		cout<<ans<<endl;
	}
	return 0;
}