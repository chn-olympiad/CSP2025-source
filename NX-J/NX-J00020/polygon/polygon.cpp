#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream cin("polygon.in");
ofstream cout("polygon=out");	
int n;
cin>>n;
int a[500];
int b[500][1000];
int sum=0;
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
for(int i=0;i<n;i++)
{
	for(int e=0;e<=i;e++)
	{
		int w=a[e]*2;
		if(a[i]<e)
		{
 			sum++;
 			b[i][e]=b[i-1][e-a[i]]+a[i];
 		}
 	}
 }
 cout<<sum;	
return 0;
}
