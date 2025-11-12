#include <bits/stdc++.h>
using namespace std;
int n;
int a=0,b=0,c=0,sum;
vector<vector<int>> p;
int findmax(int num)
{
	int m=p[num][0];
	int m1;
	for(int i=0;i<3;i++)
	{
		if(m<p[num][i])
		{
			m=p[num][i];
			m1=i;
		}
	}
	return m1;
}
int solve()
{
	sum=0;
	bool b1[n];
	memset(b1,false,sizeof(0));
	vector<int> DP;
	int s=findmax(1);
	DP[1]=p[1][s];
	if(s==1)
	{
		a++;
		b1[1]=true;
	}
	if(s==2)
	{
		b++;
		b1[1]=true;
	}
	if(s==3)
	{
		c++;
		b1[1]=true;
	}
	for(int i=1;i<n;i++)
	{
		if(!b1[i])
		{
			DP[i]=max(DP[i],DP[i+1]);
		}
	}

	return DP[n];
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>> t;
	for(int k=0;k<t;k++)
	{
		cin>> n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>> p[i][j];
			}
		}
		cout<< solve()<<endl;
	}
	
	return  0;
	
}
