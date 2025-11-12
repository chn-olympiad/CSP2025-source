#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int y=0;
	int p=0;
	int f=0;
	int a[m][n];
	int b[m*n];
	for(int i=0;i<m*n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=0;
		}                                                                                                                  
	for(int i=0;i<m*n;i++)
	{
		for(int j=0;j<m*n-1;j++)
		{
			if(b[j]<b[j+1])
			{
				p=b[j];
				b[j]=b[j+1];
				b[j+1]=p;  
			}
		}
		p=0;
	}

	}for(int i=0;i<m;i++)
	{
		for(int j=n;j>=0;j--)
		{
			a[i][j]=b[f];
			f++;
		}	
			for(int j=0;j<n;j++)
			{
				a[i][j]=b[f];
				f++;}	
		if(f==m*n)
		{
			break;
		}
		}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}            

	
}