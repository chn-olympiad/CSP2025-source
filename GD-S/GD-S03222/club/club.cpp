#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5],sum[5],q[5][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		long long sum2=0;
		memset(sum,0,sizeof sum);
		memset(q,0,sizeof q);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int cnt=1,maxn=0,las=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(maxn<a[i][j])
				{
					cnt=j;
					las=maxn;
					maxn=a[i][j];
				}
				else if(las<a[i][j])
				{
					las=a[i][j];
				}
			}
			sum[cnt]++;
			q[cnt][sum[cnt]]=maxn-las;
			sum2+=maxn;
		}
		for(int j=1;j<=3;j++)
		{
			if(sum[j]<=n/2)
			{
				continue;
			}
			int nw=1;
			sort(q[j]+1,q[j]+sum[j]+1);
			while(sum[j]>n/2)
			{
				sum2-=q[j][nw];
				nw++;
				sum[j]--;
			}
		}
		cout<<sum2<<'\n';
	}
	return 0;
} 
