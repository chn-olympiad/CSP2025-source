#include<bits/stdc++.h>
using namespace std;

int a[100000];
int b[100000];

int main()
{
	int n,m;
	int k=0;
	int shu=1,sum=0;
	cin>>n>>m;
	int num=0;
	int number=0;
	int pop=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			k=i;
			num++;
		}
		if(num>=pop)
		{
			pop++;
			for(int j=n;j>=i-k;j--)
			{
				shu=shu*j;
			}
			sum+=shu;
			shu=0;
			for(int l=i;l<n;l++)
			{
				if(b[l]<num)
				{
					number++;
					k++;
				}
			}
			if(number>0)
			{
				for(int r=number;r>=1;r--)
				{
					shu=shu*r;
				}
			}
			sum-=shu;
		}
	}
	cout<<sum;
	return 0;
}