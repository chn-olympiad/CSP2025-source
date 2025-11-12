#include<bits/stdc++.h>
using namespace std;
int m,n;
bool lc(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n][m],b[n*m];
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int w=b[1];
	sort(b,b+n*m,lc);
	for(int i=1;i<=n*m;i++)
	{
		if(w==b[i])
		{
			w=i;
		}
	}
	cout<<w/m+1<<" ";
	if(w/m+1%2==0)
	{
		cout<<n-w%m+1;
	}
	else
	{
		cout<<w%m+1;
	}
	return 0;
}
