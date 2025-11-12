#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long ar[100010]={};
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;i<=n;i++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(ar[k]+ar[j]>ar[i])
				{
					if(ar[i]+ar[j]>ar[k])
					{
						if(ar[k]+ar[i]>ar[j])
						{
							sum=sum+1;
						}  
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
