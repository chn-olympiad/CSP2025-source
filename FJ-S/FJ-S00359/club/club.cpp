#include<iostream>
using namespace std;
int a[100000][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	int n=0;
	int num[10]={0};
	int b=0,c=0,d=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{	
		cin>>n;
		int l=n/2;
		int m[n]={0};
		for(int j=0;j<n;j++)
		{
			cin>>a[j][0];
			if(a[j][0]>m[j])
			{
				m[j]=a[j][0];
				b=1;
			}
			cin>>a[j][1];
			if(a[j][1]>m[j])
			{
				m[j]=a[j][1];
				c=1;
			}	
			cin>>a[j][2];
			if(a[j][2]>m[j])
			{
				m[j]=a[j][2];
				d=1;
			}
		}
		for(int j=0;j<n;j++)
		{
			num[i]+=m[j];
		}
	}
	for(int i=0;i<t;i++)
		cout<<num[i]<<endl;
} 
