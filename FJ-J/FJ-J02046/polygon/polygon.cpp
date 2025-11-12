#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
int he[10000000];
int he_i=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	he[1]=a[0];
	he[2]=a[1];
	he[3]=a[1]+a[0];
	he[0]=0;
	he_i=4;
	int sum=0;
	int u=0;
	for(int i=2;i<n;i++)
	{
		u=0;
		/*
		for(int k=0;k<he_i;k++)
		{
			if(he[k]>a[i])
			{
				sum+=1;
				u+=1;
			}
		}
		*/
		int l=0;
		int r=he_i-1;
		while(r-l>1)
		{
			int mid=l+(r-l)/2;
			if(he[mid]>a[i])
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}
		for(int j=l;u==0 && j<=r;j++)
		{
			if(he[j]>a[i])
			{
				u=j;
//				cout<<"_"<<u<<endl;
			}
		}
		if(u!=0)
		sum+=(he_i-u);
		for(int k=0;k<he_i;k++)
		{
			he[k+he_i]=he[k]+a[i];
		}
		he_i*=2;
		sort(he,he+he_i);
			
	} 
	cout<<sum;
	
	return 0;
}
