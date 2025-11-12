#include<bits/stdc++.h>
using namespace std;

int N[100001];
int M[100001];
int Money[100001];
int sum[300002];

int main()
{
	int n,m,k;
	cin>>n,m,k;
	int c[k];
	int c_R[n];
	int MIN=100000000;
	int CMIN=100000000;
	for(int i=0;i<n;i++)
	{
		cin>>N[i]>>M[i]>>Money[i];	
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int i=0;i<n;i++)
		{
			cin>>C_R[i];
			MIN=min(MIN,C_R[i]);
		}
		c[i]+=MIN;
		CMIN=min(CMIN,c[i]);
		MIN=0;
	}
	for(int j=0;j<m*3;j+=3)
	{
		sum[j]=N[i];
		sum[j+1]=M[i];
		sum[j+2]=Money[i];
	}
	int num=sum[0],num1=sum[1],money=sum[3];
	for(int j=3;j<m*3;j+=3)
	{
		money+=sum[j+2];
		money+=sum[j+2];
		for(int i=0;i<j;i++)
		{
			if([num!=sum[j] || num!=sum[j+1])
			{
				num=sum[j+3];
			}
			if([num1!=sum[j] || num1!=sum[j+1])
			{
				num1=sum[j+3];
			}
			else
			{
				money=sum[j+2];
			}
		}
	}
	cout<<money+CMIN;
}