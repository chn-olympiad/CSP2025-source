#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,c,r;
int a[100][100];
int b[10000];

bool com(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int aj;
	for(int i = 1;i <= n*m;i++)
		cin>>b[i];
	
	aj = b[1];
	sort(b+1,b+n*m+1,com);
	
	int w;
	for(int i = 1;i <= n*m;i++)
	{
		if(b[i] == aj)
		{
			w = i;
			break;
		}
	}
	
	if(w % n == 0)
	{
		c = w / n;
		if(c % 2 == 0)
			r = 1;
		else
			r = n;
	}
	else
	{
		c = w / n + 1;
		if(c % 2 == 0)
			r = n - (w%n) + 1;
		else
			r = w % n;
	}
	
	cout<<c<<" "<<r;
	return 0;
}

