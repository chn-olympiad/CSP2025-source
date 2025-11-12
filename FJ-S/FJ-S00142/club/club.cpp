#include<bits/stdc++.h> 
using namespace std;
int liu(club[i][j])
{
	maxii+=club[i][j];
	return maxii;
}
int main()
{
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	int maxii=0;
	int t,n,1i=0,2i=0,3i=0;
	int club[3][n];
	cin>>t>>n;
	cin>>club[3][n];
	for(int j=1;j<=3;j++)
	{
		for(int i=1;i<=n;i++)
		{
				i=flase;
				club[i][j]=max(club[i][j],club[i+1][j],club[i+2][j]);
				liu(club[i][j]);
				i=ture;
				if(club[i][j]=max(club[i][j],club[i+1][j],club[i+2][j]))
				{
					1i+=1;
				}
				else if(club[i+1][j]=max(club[i][j],club[i+1][j],club[i+2][j]))
				{
					2i+=1;
				}
				else
				{
					3i+=1;
				}
		}
	}
	cout<<maxii;
	return 0;
}

