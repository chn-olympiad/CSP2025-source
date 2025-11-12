#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int rres;
int r,c;
int ind;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	cin >> a[0];
	rres = a[0];
	for(int i = 1;i<(n*m);i++)
	{
		cin >> a[i];
	}
	sort(a,a+(n*m),cmp);
	for(int i = 0;i<(n*m);i++)
	{
		if(a[i] == rres)
		{
			ind = i+1;
		}
	}
	if(ind%n == 0)
	{
		c = (ind/n);
		if((ind/n)%2 == 0) r = 1;
		else r = n;
	}
	else
	{
		c = (ind/n)+1;
		if(((ind/n)-1)%2 == 0) r = n-ind%n+1;
		else r=ind%n+1;
	}
	cout << c << " " <<r;
	return 0;
}
