#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int max,sum=0;
	long long sum1=0;
	for(int i=0;i<n;i++)
	{
		max=0;sum1=0;
		for(int j=i;j<n;j++)
		{
			if(a[j]>max) max=a[j];
			sum1+=a[j];
			if((max*2)<sum1) {
			sum++;}
		}
	}
	cout<<sum;
	return 0;
}