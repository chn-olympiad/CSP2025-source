#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sz[200]={0},r,rdj;
	cin>>n>>m;
	for(int q=1;q<=n;q++)
	{
		for(int w=1;w<=m;w++)
		{
			cin>>sz[(q-1)*m+w];
		}
	}
	r=sz[1];
	sort(sz+1,sz+n*m+1,cmp);
	for(int q=1;q<=n;q++)
	{
		for(int w=1;w<=m;w++)
		{
			if(sz[(q-1)*m+w]==r)
			{
				rdj=(q-1)*m+w;
			}
		}
	}
	int lie=(rdj-1)/n+1,hang;
	if(lie%2==1)
	{
		hang=(rdj-1)%n+1;
	}
	else
	{
		hang=lie*n+1-rdj;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
