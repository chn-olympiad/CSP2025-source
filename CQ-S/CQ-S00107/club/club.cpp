#include<iostream>
using namespace std;
int n=0,sum;
		int a[10005]={0},b[10005]={0},c[10005]={0};
int a1()
{	int de[100005]={0};
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		de[20000+b[i]-a[1]]++;
	}
	int k=0;
		for(int j=0;j<40001&&k<n/2;j++)
		{
			if(de[j]>0)
			{
				sum=sum+de[j]*(j-20000);
				k+=de[j];
			}
		}
	}
	
	
	return 0;
}
int main()
{
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>n;
		sum=0;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		a1();

		cout<<sum<<endl;
	}	
		return 0;
}
