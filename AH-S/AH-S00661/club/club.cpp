#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int ans,d[maxn][3],tot[3],n;
int num[3][maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		tot[0]=tot[1]=tot[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i][0]>>d[i][1]>>d[i][2];
			if(d[i][0]>d[i][1]&&d[i][0]>d[i][2])
			{
				ans+=d[i][0];
				num[0][++tot[0]]=d[i][0]-max(d[i][1],d[i][2]);
			}
			else
			{
				if(d[i][1]>d[i][2])
				{
					ans+=d[i][1];
					num[1][++tot[1]]=d[i][1]-max(d[i][0],d[i][2]);
				}
				else
				{
					ans+=d[i][2];
					num[2][++tot[2]]=d[i][2]-max(d[i][0],d[i][1]);
				}
			}
		}
		if(tot[0]>n/2)
		{
			sort(num[0]+1,num[0]+tot[0]+1);
			for(int i=1;i<=tot[0]-n/2;i++)
			{
				ans-=num[0][i];
			}
		}
		if(tot[1]>n/2)
		{
			sort(num[1]+1,num[1]+tot[1]+1);
			for(int i=1;i<=tot[1]-n/2;i++)
			{
				ans-=num[1][i];
			}
		}
		if(tot[2]>n/2)
		{
			sort(num[2]+1,num[2]+tot[2]+1);
			for(int i=1;i<=tot[2]-n/2;i++)
			{
				ans-=num[2][i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
