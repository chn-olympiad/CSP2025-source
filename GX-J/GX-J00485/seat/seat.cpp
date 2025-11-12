#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r","stdin");
    freopen("polygon.out","w","stdout");
	int n,m,xiao;
	long long a[10000];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int b[100][100],i=1;
	xiao=a[1];
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]<a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
	for(int x=1;x<=m;x++)
	{
		if(x%2==0)
		{
			for(int y=n;y>=0;y--)
			{
				b[x][y]=a[i];
				i++;
			}
		}
		else
		{
			for(int y=1;y<=n;y++)
			{
				b[x][y]=a[i];
				i++;
			}
		}
	}
	for(int c=1;c<=m;c++)
	{
		for(int r=1;r<n;r++)
		{
			if(b[c][r]==xiao)
			{
				cout<<c<<" "<<r;
			}
		}
	}
	return 0;
}
