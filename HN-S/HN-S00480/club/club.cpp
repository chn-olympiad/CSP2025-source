#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n,x,y,z;
	int a[n+5][5],dp[n+5],v[5],c,h;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			//cout<<endl<<i<<".1:"<<a[i][1]<<" "<<i<<".2:"<<a[i][2]<<" "<<i<<".3:"<<a[i][3]<<" "<<endl;
		}
			for(int i=1;i<=n;i++)
			{
				//cout<<"j="<<j<<endl;
				memset(v,0,sizeof(v));
				for(int j=i;j>0;j--)
				{
					//cout<<"i="<<i<<endl;
					for(int k=1;k<=3&&v[k]<=n/2;k++)
					{
						//cout<<"k="<<k<<endl;
						//cout<<"dj="<<dp[j]<<" dj-1="<<dp[j-1]<<" aik="<<a[i][k]<<endl;
						c=dp[j];
						dp[j]=max(dp[j],dp[j-1]+a[i][k]);
						if(c!=dp[j])h=k;
						//cout<<"dj="<<dp[j]<<" dj-1="<<dp[j-1]<<" aik="<<a[i][k]<<endl;
					}
					v[h]++;
				}
			}
		cout<<dp[n]<<endl;
	}
	return 0;
}
