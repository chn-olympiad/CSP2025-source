#include<bits/stdc++.h>
using namespace std;
long long t,n,a[4],k,oth[4][100010],sum[4],dfir,dsec,fir,sec,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		ans=0;
		cin>>n;
		k=n/2;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[1]>>a[2]>>a[3];
			fir=0;sec=0;dfir=-1;dsec=-1;
			for(long long j=1;j<=3;j++)
			{
				if(a[j]>dfir)
				{
					dsec=dfir;
					sec=fir;
					dfir=a[j];
					fir=j;
				}
				else if(a[j]>dsec)
				{
					dsec=a[j];
					sec=j;
				}
			}
			oth[fir][sum[fir]]=dfir-dsec;
			sum[fir]++;
			ans+=dfir;
		}
		for(long long i=1;i<=3;i++)
		{
			if(sum[i]>k)
			{
				sort(oth[i],oth[i]+sum[i]);
				for(long long j=0;j<sum[i]-k;j++)
				{
					ans-=oth[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
