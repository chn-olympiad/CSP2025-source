//GZ-S00159 北京师范大学贵阳附属中学 张景奕 
#include <bits/stdc++.h>
using namespace std;
int n,T;
const int N=1e5+7;
int a[N][3];
int d[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		int ans=0;
		int c[3]={0,0,0};
		vector <short> tg(n+1,-1);
		for(int i=1;i<=n;i++)
		{
			int maxi=max({a[i][0],a[i][1],a[i][2]});
			d[i]=a[i][0]+a[i][1]+a[i][2]-maxi-min({a[i][0],a[i][1],a[i][2]});
			for(int k=0;k<3;k++)
			{
				if(a[i][k]==maxi)
				{
					c[k]++;
					tg[i]=k;
					break;
				}
			}
			ans+=maxi;
			d[i]=maxi-d[i];
		}
		if(c[0]<=(n>>1)&&c[1]<=(n>>1)&&c[2]<=(n>>1))
		{
			cout<<ans<<'\n';
			continue;
		}
		short mor=-1;
		for(int i=0;i<3;i++)
		{
			if(c[i]>(n>>1))
			{
				mor=i;
				break;
			}
		}
		vector <int> srt(c[mor]);
		int hh=0;
		for(int i=1;i<=n;i++)
		{
			if(tg[i]==mor)
			{
				srt[hh++]=d[i];
			}
		}
		sort(srt.begin(),srt.end());
		for(int i=0;i<(c[mor]-n/2);i++)
		{
			ans-=srt[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
