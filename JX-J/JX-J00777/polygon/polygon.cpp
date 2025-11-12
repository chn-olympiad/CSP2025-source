#include<bits/stdc++.h>
using namespace std;
int a[5000],cnt=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				int l=a[j];
				a[j]=a[j+1];
				a[j+1]=l;
			}
		}
	}
	if(a[0]+a[1]+a[2]>a[0]*2)
	{
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
