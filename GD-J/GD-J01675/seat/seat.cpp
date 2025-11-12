#include<bits/stdc++.h>
using namespace std;
struct student
{
	int id,score;
}a[105];
bool cmp(student a,student b)
{
	return a.score>b.score;
}
int n,m,t[15][15],s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].score,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				t[j][i]=a[++s].id;
		}
		else
		{
			for(int j=n;j>=1;j--)
				t[j][i]=a[++s].id;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(t[i][j]==1)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
