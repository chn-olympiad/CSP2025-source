#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int q=n*m;
	vector<int> a(q);
	for(int i=0;i<q;i++)
	{
		cin>>a[i];
	}
	int R=a[0];
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
	for(int i=0;i<arr;i++)
	{
		if(a[i]==R)
		{
			cout<<i/n+1<<' ';
			if((i/n+1)%2==1)
			{
				cout<<i%n+1;
			}
			else
			{
				cout<<m-i%n;
			}
			break;
		}
	}
	return 0;
}
