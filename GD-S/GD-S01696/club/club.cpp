#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,n,x,y,z;
long long ans,di1[N],idx1,di2[N],idx2,di3[N],idx3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=idx1=idx2=idx3=0;
		for(long long i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if(x>=y&&x>=z)
			{
				di1[++idx1]=x-max(y,z);
				ans+=x;
			}
			else if(y>=x&&y>=z)
			{
				di2[++idx2]=y-max(x,z);
				ans+=y;
			}
			else if(z>=x&&z>=y)
			{
				di3[++idx3]=z-max(x,y);
				ans+=z;
			}
		}
		if(idx1>n/2)
		{
			sort(di1+1,di1+1+idx1);
			for(long long i=1;i<=idx1-n/2;i++)
			{
				ans-=di1[i];
			}
		}
		else if(idx2>n/2)
		{
			sort(di2+1,di2+1+idx2);
			for(long long i=1;i<=idx2-n/2;i++)
			{
				ans-=di2[i];
			}
		}
		else if(idx3>n/2)
		{
			sort(di3+1,di3+1+idx3);
			for(long long i=1;i<=idx3-n/2;i++)
			{
				ans-=di3[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
