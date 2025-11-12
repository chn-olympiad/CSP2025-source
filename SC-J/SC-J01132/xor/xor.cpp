#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
long long n,k;
long long a[200005];
long long flag[200005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag1=1;//情况A; 
	int flag2=1;//情况B; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		if(a[i]!=1)
		{
			flag1=0;	
		}
		if((a[i]!=1)&&(a[i]!=0))
		{
			flag2=0;
		}
	}
	if(flag1==1)
	{
		cout<<n/2;
		return 0;
	}
	else if(flag2==1)
	{
		if(k==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
			cout<<ans;
			return 0;
		} 
		else if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
					flag[i]=1;
				}
				if((a[i]==1)&&(flag[i]==0))
				{
					if((a[i+1]==1)&&(flag[i]==0))
					{
						ans++;
						//cout<<i<<"     "<<i+1<<endl;
						i++;
						flag[i-1]=1;
						flag[i]=1;
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}