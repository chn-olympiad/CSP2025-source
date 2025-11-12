#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		for(int k=1;k<=n;k++)
    		{
    			if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))*2) sum++;
    			
			}
		}
	}
	cout<<sum;
	return 0;
}
