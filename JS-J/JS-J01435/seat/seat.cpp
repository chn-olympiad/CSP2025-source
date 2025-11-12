#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
int ansx,ansy;
int n,m;
struct Students
{
	int score;
	bool flag;
}p[105];
bool comp(Students x,Students y)
{
	return x.score>y.score;
}
void f(int x,int y,int k,bool down)
{
	if(p[k].flag==true)
	{
		ansx=x,ansy=y;
		return;
	}
	if(down&&x<n)
	{
		f(x+1,y,k+1,down);
	}else if(down&&x==n)
	{
		f(x,y+1,k+1,!down);
	}else if(!down&&x>1)
	{
		f(x-1,y,k+1,down);
	}else if(!down&&x==1)
	{
		f(x,y+1,k+1,!down);
	}else
	{
		cout<<"error"<<endl;
		return;
	}
	
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>p[i].score;
		p[i].flag=false;
	}
	p[1].flag=true;
	
	sort(p+1,p+n*m+1,comp);
	f(1,1,1,true);
	cout<<ansy<<' '<<ansx<<endl;
	return 0;
}
