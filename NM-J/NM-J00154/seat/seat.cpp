#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mark[105];
	for(int i=1;i<=n*m;i++)
	{
		cin>>mark[i];
	}
	int r=mark[1];
	sort(mark+1,mark+n*m+1,com);
	for(int i=1;i<=n*m;i++)
	{
		if(mark[i]==r)
		{
			r=i;
			break;
		}
	}
	int lie=(r+n-1)/n;
	int hang;
	if(lie%2==1)
	{
		hang=r%n;
		if(hang==0)
		{
			hang=n;
		}
	}
	if(lie%2==0)
	{
		hang=n-r%n+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
