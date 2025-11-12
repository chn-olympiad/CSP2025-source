#include <bits/stdc++.h>
using namespace std;
bool cmp(long long X,long long Y)
{
	return X>Y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		long long a[100005][5],b[100005];
		long long n,sum[5]={0,0,0,0,0};
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
		}
		int o=(a[1][1]+a[2][2]),s=(a[1][1]+a[2][3]),u=(a[1][2]+a[2][1]),x=(a[1][2]+a[2][3]),y=(a[1][3]+a[2][1]),z=(a[1][3]+a[2][2]);
		int tt=max(o,s),tt1=max(tt,u),tt2=max(tt1,x),tt3=max(tt2,y),tt4=max(tt3,z);
		if(n==2)
		{
			cout<<tt4<<"\n";
			continue;
		}
		sort(b+1,b+n+1,cmp);
		int ttmp=n/2;
		for(int i=1;i<=ttmp;i++)
		{
			ans+=b[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
