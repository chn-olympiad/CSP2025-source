#include <bits/stdc++.h>
using namespace std;
int a[101];
int seat[11][11];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,goal_score;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
		cin>>a[i];
		if(i==0)
		{
			goal_score=a[i];
		}
	}
	sort(a,a+n*m,cmp);
	int t=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				seat[j][i]=a[t];
				t++;
			}
		}else{
			for(int j=n;j>=1;j--)
			{
				seat[j][i]=a[t];
				t++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(seat[i][j]==goal_score)
			{
				cout<<j<<" "<<i;
			}
			//cout<<seat[i][j]<<" ";
		}
		//cout<<endl;
	}
	return 0;
}
