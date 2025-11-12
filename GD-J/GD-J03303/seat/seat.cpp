#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

struct is_r
{
	int score;
	bool is;
};

bool cmp(is_r x,is_r y)
{
	return x.score>y.score;
}

is_r a[105];
int b[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m; //n is hang   m is lie
	int tol=n*m;
	for(int i=1; i<=tol; i++)
	{	
		a[i].is=false;
	}
	a[1].is=true;
	for(int i=1; i<=tol; i++)
	{	
		cin>>a[i].score;
	}
	sort(a+1,a+tol+1,cmp);
	int pm=0;
	for(int i=1; i<=tol; i++)
	{
		if(a[i].is==true) pm=i;
	}
	int lie=ceil(pm*1.0/n);
	int hang=0;
	if(lie & 1) 
	{
		hang=pm%n;
		if(hang==0) hang=n;
	}
	else
		hang=n-pm%n+1;
	cout<<lie<<" "<<hang;
	return 0;
}







