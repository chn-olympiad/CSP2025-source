#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int num=0;
	cin>>n>>m;
	string a[n],b[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[n];
	}
	for(int j=0;j<n;;j++)
	{
		cin>>b[m];
	}
	for(int p=0;p<m;p++)
	{
		for(int i=0;i<b.size();i++)
		{
			for(int j=i;j<b.size();j++)
			{
				if(a[i]==b[j])
				{
					a[i]=b[j];
					num++;
				}
			}
		}
		cout<<num;
		num=0;
	}
	return 0;
}