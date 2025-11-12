#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int T,n,a[100005][5];
int max(int x,int y)
{
	return x>y?x:y;
}
int min(int x,int y)
{
	return x<y?x:y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		vector<int>c[5];
		vector<int>b;
		scanf("%d",&n);
		int m=n/2;
		for(int i=1;i<=n;i++)
			for(int t=1;t<=3;t++)
				scanf("%d",&a[i][t]);
		for(int i=1;i<=n;i++)
		{
			c[1].push_back(a[i][1]);
			c[2].push_back(inf);
			c[3].push_back(inf);
		}
		int s=n,f=0;
		for(int i=0;i<n;i++)
			if(c[1][i]<a[i+1][2])
			{
				c[2][i]=a[i+1][2];
				c[1][i]=inf;
				s--;
				f++;
			}
			else 
				b.push_back(i);
		sort(b.begin(),b.end(),[](int x,int y)
		{
			int i=x+1,t=y+1;
			if(a[i][2]-a[i][1]==a[t][2]-a[i][1])
				return a[i][3]-a[i][2]>a[t][3]-a[t][2];
			return a[i][2]-a[i][1]>a[t][2]-a[t][1];
		});
		for(int i=0;i<min(b.size(),max(s-m,0));i++)
		{
			c[2][b[i]]=a[b[i]+1][2];
			c[1][b[i]]=inf;
			f++;
		}
		b.clear();
		for(int i=0;i<n;i++)
		{
			if(c[2][i]==inf)
				continue;
			if(c[2][i]<a[i+1][3])
			{
				c[3][i]=a[i+1][3];
				c[2][i]=inf;
				f--;
			}
			else
				b.push_back(i);
		}
		sort(b.begin(),b.end(),[](int x,int y)
		{
			int i=x+1,t=y+1;
			return a[i][3]-a[i][2]>a[t][3]-a[t][2];
		});
		for(int i=0;i<min(b.size(),max(f-m,0));i++)
		{
			c[3][b[i]]=a[b[i]+1][3];
			c[2][b[i]]=inf;
		}
		int ans=0;
		for(int t=0;t<n;t++)
			for(int i=1;i<=3;i++)
				ans+=c[i][t]==inf?0:c[i][t];
		printf("%d\n",ans);
	}
	return 0;
}
