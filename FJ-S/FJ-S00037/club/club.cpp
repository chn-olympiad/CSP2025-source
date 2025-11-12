#include<iostream>
#include<algorithm>
using namespace std;
long long t,a[100001],b[100001],c[100001],cnt1=0,cnt2=0,cnt3=0,n,cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt1=0,cnt2=0,cnt3=0,cnt=0;
		for(long long i=1;i<=n;i++)
		{
			long long x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z)
			{
				cnt1++,a[cnt1]=x-max(y,z);
				cnt+=x;
			}
			else
			if(y>=x&&y>=z)
			{
				cnt2++,b[cnt2]=y-max(x,z);
				cnt+=y;
			}
			else
			{
				cnt3++,c[cnt3]=z-max(x,y);	
				cnt+=z;
			}
		}
		if(cnt1>(n/2))
		{
			sort(a+1,a+cnt1+1);
			int sum=0;
			for(int i=1;i<=(cnt1-(n/2));i++)
			{
				sum+=a[i];
			}
			cout<<cnt-sum;
		}
		else
		if(cnt2>(n/2))
		{
			sort(b+1,b+cnt1+1);
			int sum=0;
			for(int i=1;i<=(cnt2-(n/2));i++)
			{
				sum+=b[i];
			}
			cout<<cnt-sum;
		}
		else
		if(cnt3>(n/2))
		{
			sort(c+1,c+cnt3+1);
			int sum=0;
			for(long long i=1;i<=(cnt3-(n/2));i++)
			{
				sum+=c[i];
			}
			cout<<cnt-sum;
		}
		else
		cout<<cnt;
		cout<<endl;
	}
	return 0;
}
