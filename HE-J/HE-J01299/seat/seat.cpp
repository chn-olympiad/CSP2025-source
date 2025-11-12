#include <bits/stdc++.h>
using namespace std;
int a[1000];
int mp[100][100];
int ax,ay;
bool cmp(int a,int b)
{
	return a>b; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//ÐÐÓëÁÐ 
	cin>>n>>m;
	int sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+sum+1,cmp);
	int s=1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)	
		{
			for(int j=1;j<=n;j++)
			{
				mp[j][i]=a[s];
				
				if(a[s]==R)
				{
					ax=i;
					ay=j;
				}
				s++;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				mp[j][i]=a[s];
				if(a[s]==R)
				{
					ax=i;
					ay=j;
				}
				s++;
			}	
		 } 
	}
	
	cout<<ax<<" "<<ay;
	return 0;
} 
