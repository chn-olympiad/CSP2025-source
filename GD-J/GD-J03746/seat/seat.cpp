#include<bits/stdc++.h>
using namespace std;
int grade[105];
int seat[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a;
	for(int i=0;i<n*m;i++)
	{
		cin>>grade[i];
	}
	a=grade[0];
	sort(grade,grade+n*m);
	int num;
	for(int i=n*m-1,j=1;i>=0;i--)
	{
		if(grade[i]==a)
		{
			num=j;
			break;
		}
		j++;
	}
	int se=1;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
		{
			seat[j][i]=se;
			se++;
		}
		if(i+1>m)break;
		for(int j=n;j>=1;j--)
		{
			seat[j][i+1]=se;
			se++;
		}
	}
	int n1,m1;
	for(int i=1;i<=m;i++)
	{
		int check=0;
		for(int j=1;j<=n;j++)
		{
			if(seat[i][j]==num)
			{
				n1=j,m1=i;
				check=1;
				break;
			}
		}
		if(check==1)break;
	}
	cout<<n1<<" "<<m1;
	return 0;
}
