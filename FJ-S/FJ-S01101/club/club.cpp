#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[3];
long long ans,d1[100001],d2[100001],d3[100001],a1,a2,a3,delt;
long long det(long long x,long long y,long long z)
{
	if(y<z) swap(y,z);
	if(x<y) swap(x,y);
	if(y<z) swap(y,z);
	return x-y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a1,&a2,&a3);
			delt=det(a1,a2,a3);
			if(a1>=a2&&a1>=a3) 
				cnt[1]++,ans+=a1,d1[cnt[1]]=delt;
			else
				if(a2>=a1&&a2>=a3) 
					cnt[2]++,ans+=a2,d2[cnt[2]]=delt;
				else
					cnt[3]++,ans+=a3,d3[cnt[3]]=delt;
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2) 
			cout<<ans<<endl;
		else
			if(cnt[1]>n/2)
			{
				sort(d1+1,d1+cnt[1]+1);
				for(int i=1;i<=cnt[1]-(n/2);i++)
					ans-=d1[i];
				cout<<ans<<endl;
			}
			else
				if(cnt[2]>n/2)
				{
					sort(d2+1,d2+cnt[2]+1);
					for(int i=1;i<=cnt[2]-(n/2);i++)
						ans-=d2[i];
					cout<<ans<<endl;
				}
				else
				{
					sort(d3+1,d3+cnt[3]+1);
					for(int i=1;i<=cnt[3]-(n/2);i++)
						ans-=d3[i];
					cout<<ans<<endl;
				}
	}
	return 0;
}
