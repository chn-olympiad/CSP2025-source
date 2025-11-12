#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int num[1000];
int num1[1000];
int mark[1000];
int x[20];
int y[20];
int last[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>num[i];
		num1[i]=num[i];
	}
	if(n==1&&m==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(num[i]>num[j])
			{
				mark[i]++;
			}
		}
	}
	
	
	for(int i=1;i<=n*m;i++)
	{
		num[n*m-mark[i]]=num1[i];
	}
	int ll=0;
	for(int i=1;i<=n*m;i++)
	{
		ll++;
		if(num[i]==num1[i])
		{
			break;
		}
		
	}
	cout<<ll;
	return 0;
} 
