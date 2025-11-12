#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,count=1;
	cin>>m>>n;
	int dp[n+1][m+1]={},score[n*m+1]={};
	for(int i=1;i<=m*n;i++)
	{
		cin>>score[i];
	}
	int ScoreR=score[1];
	for(int i=1;i<=m*n;i++)
	{
		for(int j=i;j<=m*n-1;j++)
		{
			if(score[j]<score[j+1])
				swap(score[j],score[j+1]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				dp[j][i]=score[count];
				count++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				dp[j][i]=score[count];
				count++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ScoreR==dp[j][i])
			{
				cout<<i<<" "<<j;
			}
			else continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
