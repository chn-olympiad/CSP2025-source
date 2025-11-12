#include<bits/stdc++.h>
using namespace std;
int t,m[1000001][4],n,ans,cha[4][1000001],maxt,maxx,b[4],minn,mint,z[1000001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		z[1]=z[2]=z[3]=0;
		cin>>n;
		ans=0;
		memset(m,0,sizeof(m));
		memset(z,0,sizeof(z));
		memset(b,0,sizeof(b));
		memset(cha,0,sizeof(cha));
		for(int i=1;i<=n;i++)
		{
			cin>>m[i][1]>>m[i][2]>>m[i][3];
			maxx=-99999999;maxt=0;
			for(int j=1;j<=3;j++)
			{
				if(m[i][j]>maxx)
				{
					maxx=m[i][j];
					maxt=j;
				}
			}
			b[maxt]++;
			minn=99999999;
			mint=0;
			for(int j=1;j<=3;j++)
			{
				if(j!=maxt&&(maxx-m[i][j])<=minn)
				{
					mint=j;
					minn=(maxx-m[i][j]);
				}
			}
			cha[maxt][++z[maxt]]=minn;
			ans+=maxx;
		}
		for(int i=1;i<=3;i++)
		{
			if(b[i]>(n/2))
			{
				sort(cha[i]+1,cha[i]+z[i]+1);
				for(int j=1;j<=(b[i]-(n/2));j++)
				{ans-=cha[i][j];}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
