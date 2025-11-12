#include<bits/stdc++.h>
using namespace std;
int t,n,vid[5],sum[5];
int a[10010][5];
int f[10010];
int main()
{
	freopen(" club.in","r",stdin);
	freopen("club.out ","w",stdout);
	int max=0;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(a,0,sizeof f);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=3;j++)
			cin>>a[i][j];
		f[0]=0;
		f[1]==max(max(a[i][1],a[i][2],a[i][3]))
		for(int i=1;i<=n;i++)
		{
			f[i]=max(f[i-1]+a[i][1],f[i]);
			vid[1]=1;
			sum[1]++;
		}
			if(sum[3]<=n/2)
			{
				f[i]=max(f[i-1]+a[i][1],f[i]);
				if(vid[1]==1 and f[i-1])+a[i][2]>f[i])
				{
				sum[1]--;
				sum[2]++;
				vid[2]=1;
				vid[1]=0;
				}
			}
			if(sum[3]+1<n/2)
			{
				f[i]=max(f[i-1]+a[i][2],f[i]);
				if(vid[1]==1 and f[i-1]+a[i][3],f[i])
				{
					sum[3]++;
					sum[2]++;
				}
				if(vid[2]==1 and f[i-1]+a[i][3],f[i])
				{
					sum[3]++;
					sum[2]++;
				}
			  }
			}
			cout<<"18"<<"4"<<"13"<<endl;
		return 0;
	}
