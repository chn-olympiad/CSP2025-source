#include<bits/stdc++.h>
using namespace std;
int n,m;
int tl;
int a[20][20],b[110];
bool f;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	tl = b[1];
	sort(b+1,b+n*m+1,cmp);
	int x = 1,y =1;
	int s = 1;
/*	for(int i = 1;i<=n*m;i++)
	{
		cout<<b[i]<<endl;
	}*/
	while(1)
	{
	//	cout<<x<<y<<endl;
		a[x][y] = b[s];
		if(b[s]==tl)
		{
			cout<<y<<" "<<x;
			break;
		}
		if(s%n==0)
		{
			y++;
			f=1;
		}
		if(y%2==1&&!f)
		{	
			x++;
		}
		if(y%2==0&&!f)
		{
			x--;
		}
/*		if(s==n*m)
		{
			break;
		}*/
		s++;
		f =0;
	}
	return 0;
}

