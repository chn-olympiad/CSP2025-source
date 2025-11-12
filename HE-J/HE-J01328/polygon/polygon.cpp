#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum,mx,ans;
const long mod= 998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	if(n<3)
	{
		cout<<0;
		return 0;
	} 
	else{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					sum=a[i]+a[j]+a[k];
					mx=max(max(a[i],a[j]),a[k]);
					if(sum>2*mx)
					{
						ans++;
					}
				}
			} 
		}
		if(n>=4)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					for(int k=j+1;k<=n;k++)
					{
						for(int l=k+1;l<=n;l++)
						{
							sum=a[i]+a[j]+a[k]+a[l];
							mx=max(a[l],max(max(a[i],a[j]),a[k]));
							if(sum>2*mx)
							{
								ans++;
							}
						}
					}
				} 
			}
			if(n>=5)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						for(int k=j+1;k<=n;k++)
						{
							for(int l=k+1;l<=n;l++)
							{
								for(int o=l+1;o<=n;o++)
								{
									sum=a[i]+a[j]+a[k]+a[l]+a[o];
									mx=max(a[o],max(a[l],max(max(a[i],a[j]),a[k])));
									if(sum>2*mx)
									{
										ans++;
									}
								}
							}
						}
					} 
				}
			}
		}
	}
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
