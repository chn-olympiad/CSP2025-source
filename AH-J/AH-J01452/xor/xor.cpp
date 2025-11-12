#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N];
int cnt=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<" ";
		if(a[i]>1)f=0;
	}
	//cout<<endl;
	if(f==1)
	{
		if(k>1)
		{
			printf("0");
			return 0;
		}
		if(k==1)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					cnt++;
			printf("%d",cnt);
			return 0;
		}
		if(k==0)
		{
			int cnt1=0,cnt0=0,ans1=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
					ans1+=cnt1/2,cnt1=0,cnt0++;
				else cnt1++;
			}
			printf("%d",ans1+cnt0);
		}
		return 0;
	}
	int last=n+1,ans=0;
	for(int i=n-1;i>0;i--)
	{
		for(int j=i;j<last;j++)
		{
			if((b[j]^b[i-1])==k)
			{
				ans++;
				last=i;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
