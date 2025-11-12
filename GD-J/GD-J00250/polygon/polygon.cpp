#include<iostream>
#include<algorithm>
using namespace std;
int a[5005]={0},sum[5005]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	int kk=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		kk+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3&&kk>2*a[3])
	{
		cout<<1;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=3;
	while(r<=n)
	{
		if(sum[r]-sum[l]<=2*a[r])
		{
			r+=1;
		}
		else
		{
			ans+=1;
			int i=0;
			while(sum[r]-sum[l+1]>2*a[r]&&r-l>3)
			{
				//cout<<l<<" "<<r<<endl;
				ans+=1;
				l+=1;
			}
			r+=1;
		}
	}
	cout<<ans;
	return 0;
}
