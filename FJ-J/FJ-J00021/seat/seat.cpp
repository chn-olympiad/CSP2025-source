#include <bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	int biao;
}a[110];
bool cmp(stu x,stu y)
{
	return x.score>y.score;
}
int cnt=1;
int b[10][10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i].score;
		a[0].biao=1;
	}
	int weizhi;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i].biao==1)
		{
			weizhi=i+1;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<m;j++)
			{
				b[i][j]=cnt;
				cnt++;
			}
		}
		if(i%2==1)
		{
			for(int j=m-1;j>=0;j--)
			{
				b[i][j]=cnt;
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(b[i][j]==weizhi)
			{
				cout<<i+1<<" "<<j+1;
				break;
			}
		}
	}
	/*
	呜呜呜这题我更要AC了，我都把性质手玩出来了呜呜呜
	AC
	AC
	AC
	AC 
	*/
	return 0;
}
