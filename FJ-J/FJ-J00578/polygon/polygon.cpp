#include<bits/stdc++.h>
using namespace std;
int n,a[5002],b[5002],cnt,s,q;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout);
	q=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{	
		int j=i+1;
		for(;j<=n;)
		{			 
			int sum=a[i]+a[j],max1=a[i],k=1;
			s=j+1;
			while(k<=q+2)
			{
				k++;
				j++;
				max1=max(a[j],max1);
				sum+=a[j];					
			}
			if(sum>max1*2)
			{
				cnt++;
			}
			j=s;
			q+=2;
		}
					
	}
	cout<<cnt;
	return 0;
}

