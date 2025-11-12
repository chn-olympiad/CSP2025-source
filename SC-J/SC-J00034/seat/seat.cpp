#include<bits/stdc++.h>
using namespace std;
int seat[20][20];
struct NODE
{
	int score;
	bool r;
}a[110];
bool cmp(NODE a,NODE b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int nowx=1,nowy=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i].score;
		if(i==1)
		{
			a[i].r=true;
		}
		else
		{
			a[i].r=false;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;a[i].r==false;i++)
	{
		if(nowx%2==1&&nowy==n)nowx++;
		else if(nowx%2==0&&nowy==1)nowx++; 
		else if(nowx%2==0)nowy--; 
		else if(nowx%2==1)nowy++; 
	}
	cout<<nowx<<' '<<nowy;
	return 0;
 } 