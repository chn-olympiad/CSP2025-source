#include<bits/stdc++.h>
using namespace std;
struct ans_val
{
	int ways;
	int value;
};
int xo(int a,int b)
{
	queue<int> A;
	queue<int> B;
	if(a<b)
	{
		int col=a;
		a=b;
		b=col;
	}
	while(a!=0)
	{
		if(a%2==0)
		{
			A.push(0);
			a/=2;
		}
		if(a%2==1)
		{
			A.push(1);
			a=(a-1)/2;
		}
	}
	while(b!=0)
	{
		if(b%2==0)
		{
			B.push(0);
			b/=2;
		}
		if(b%2==1)
		{
			B.push(1);
			b=(b-1)/2;
		}
	}
	queue<int> C;
	while(!A.empty())
	{
		int n=A.front();
		A.pop();
		int m;
		if(B.empty())
		{
			m=0;
		}
		else
		{
			m=B.front();
			B.pop();
		}
		if(n==m)
		{
			C.push(0);
		}
		else
		{
			C.push(1);
		}
	}
	int c=0;
	int po=1;
	while(!C.empty())
	{
		if(C.front()==1)
		{
			c+=po;
		}
		C.pop();
		po*=2;
	}
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	ans_val dp[n][n];
	for(int i=0;i<n;i++)
	{
		cin>>dp[0][i].value;
		if(dp[0][i].value==k)
		{
			dp[0][i].ways=1;
		}
		else
		{
			dp[0][i].ways=0;
		}
	}
	int corr;
	int max_mid;
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			dp[i][j].value=xo(dp[i-1][j-1].value,dp[0][j].value);
			if(dp[i][j].value==k)
			{
				corr=1;
			}
			else
			{
				corr=0;
			}
			max_mid=max(dp[i-1][j-1].ways+dp[0][j].ways,dp[i-1][j].ways+dp[0][j-i].ways);
			dp[i][j].ways=max(max_mid,corr);
		}
	}
	cout<<dp[n-1][n-1].ways;
	return 0;
}
