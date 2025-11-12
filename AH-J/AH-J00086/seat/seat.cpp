#include <bits/stdc++.h>
#define up 1
#define down 0
using namespace std;
int n,m;
int score[105],flag[105],place[10][10],hang=1,lie=1,nowrank=1;
bool direction=down;
int a[11][11];
void change()
{
	if (direction==up) direction=down;
	if (direction==down) direction=up;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>score[i];
	
	sort(score+1,score+n*m+1);
	for (int i=n;i>=1;i--)
	{
		for (int j=m;j>=1;j--)
			place[i][j]=
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			cout<<place[i][j]<<' ';
		cout<<endl;
	}
}
//chu ti ren 4 quan jia
