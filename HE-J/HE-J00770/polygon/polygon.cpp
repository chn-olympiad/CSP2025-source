#include<bits/stdc++.h>
using namespace std;
int pl(int a[],int n,int max)
{
	for(int i=max;i>0;i--)
	{
		
	}
}
int main()
{
	int n;
	vector<int> a(n);
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		a[i]=tmp;
	}
	int arr=a.size();
	int v;
	for(int i=0;i<arr;i++)
	{
		for(int j=i;j<arr;j++)
		{
			if(a[j]>a[i])
			{
				v=a[i];
				a[i]=a[j];
				a[j]=v;
			}
		}
	}
	int sum=3;
	tmp=a.size();
	while(sum>tmp)
	{
		for(int i=tmp;i>2;i--)
		{
			
		}
	}
	cout<<9;
}
