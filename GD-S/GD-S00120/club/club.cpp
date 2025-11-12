#include<set>
#include<cstdio>
using namespace std;
int t,n,s[100005][5],cnt[5];long long ans;
set<pair<long long,int>>x[5][5];
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	f=(f<<1)+(f<<3)+ch-48,ch=getchar();
	return f;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();while(t--)
	{
		n=read(),ans=0;for(int i=1;i<=n;i++)
		s[i][1]=read(),s[i][2]=read(),s[i][3]=read();
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		x[i][j].clear();
		for(int i=1;i<=n;i++)
		{
			if(s[i][1]>=s[i][2]&&s[i][1]>=s[i][3])
			{
				cnt[1]++,x[1][2].insert({s[i][1]-s[i][2],i}),
				x[1][3].insert({s[i][1]-s[i][3],i}),ans+=s[i][1];
				if(cnt[1]>n/2)
				{
					long long x1=1e18,x2=1e18;cnt[1]--;
					if(cnt[2]<n/2) x1=(*x[1][2].begin()).first;
					if(cnt[3]<n/2) x2=(*x[1][3].begin()).first;
					if(x1<=x2)
					{
						ans-=x1;cnt[2]++;
						int wh=(*x[1][2].begin()).second;
						x[1][2].erase({s[wh][1]-s[wh][2],wh});
						x[1][3].erase({s[wh][1]-s[wh][3],wh});
						x[2][1].insert({s[wh][2]-s[wh][1],wh});
						x[2][3].insert({s[wh][2]-s[wh][3],wh});
					}
					else
					{
						ans-=x2;cnt[3]++;
						int wh=(*x[1][3].begin()).second;
						x[1][2].erase({s[wh][1]-s[wh][2],wh});
						x[1][3].erase({s[wh][1]-s[wh][3],wh});
						x[3][1].insert({s[wh][3]-s[wh][1],wh});
						x[3][2].insert({s[wh][3]-s[wh][2],wh});
					}
				}
			}
			else if(s[i][2]>=s[i][1]&&s[i][2]>=s[i][3])
			{
				cnt[2]++,x[2][1].insert({s[i][2]-s[i][1],i}),
				x[2][3].insert({s[i][2]-s[i][3],i}),ans+=s[i][2];
				if(cnt[2]>n/2)
				{
					long long x1=1e18,x2=1e18;cnt[2]--;
					if(cnt[1]<n/2) x1=(*x[2][1].begin()).first;
					if(cnt[3]<n/2) x2=(*x[2][3].begin()).first;
					if(x1<=x2)
					{
						ans-=x1;cnt[1]++;
						int wh=(*x[2][1].begin()).second;
						x[2][1].erase({s[wh][2]-s[wh][1],wh});
						x[2][3].erase({s[wh][2]-s[wh][3],wh});
						x[1][2].insert({s[wh][1]-s[wh][2],wh});
						x[1][3].insert({s[wh][1]-s[wh][3],wh});
					}
					else
					{
						ans-=x2;cnt[3]++;
						int wh=(*x[2][3].begin()).second;
						x[2][1].erase({s[wh][2]-s[wh][1],wh});
						x[2][3].erase({s[wh][2]-s[wh][3],wh});
						x[3][1].insert({s[wh][3]-s[wh][1],wh});
						x[3][2].insert({s[wh][3]-s[wh][2],wh});
					}
				}
			}
			else if(s[i][3]>=s[i][1]&&s[i][3]>=s[i][2])
			{
				cnt[3]++,x[3][1].insert({s[i][3]-s[i][1],i}),
				x[3][2].insert({s[i][3]-s[i][2],i}),ans+=s[i][3];
				if(cnt[3]>n/2)
				{
					long long x1=1e18,x2=1e18;cnt[3]--;
					if(cnt[1]<=n/2) x1=(*x[3][1].begin()).first;
					if(cnt[2]<=n/2) x2=(*x[3][2].begin()).first;
					if(x1<=x2)
					{
						ans-=x1;cnt[1]++;
						int wh=(*x[3][1].begin()).second;
						x[3][1].erase({s[wh][3]-s[wh][1],wh});
						x[3][2].erase({s[wh][3]-s[wh][2],wh});
						x[1][2].insert({s[wh][1]-s[wh][2],wh});
						x[1][3].insert({s[wh][1]-s[wh][3],wh});
					}
					else
					{
						ans-=x2;cnt[2]++;
						int wh=(*x[3][2].begin()).second;
						x[3][1].erase({s[wh][3]-s[wh][1],wh});
						x[3][2].erase({s[wh][3]-s[wh][2],wh});
						x[2][1].insert({s[wh][2]-s[wh][1],wh});
						x[2][3].insert({s[wh][2]-s[wh][3],wh});
					}
				}
			}
		}printf("%lld\n",ans);
	}
}
