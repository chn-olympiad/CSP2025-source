#include<bits/stdc++.h>
using namespace std;

int a[105];
int mp[15][15];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int len = n*m;
	
	for(int i=1;i<=len;i++)
	{
		cin >> a[i];
	}
	
	int Little_R = a[1];
	
	sort(a+1,a+len+1,greater<>());
	
	int idx;
	for(int i=1;i<=len;i++)
	{
		if(a[i] == Little_R) 
		{
			idx = i;
			break;
		}
	}
	
	int del;
	for(int i=1;i<=n;i++)//n
	{
		for(int j=1;j<=m;j++)//m
		{
			if(j%2 == 1) del = i;
			else del = n+1-i;
			if(n*(j-1) + del == idx)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	

	return 0;
}