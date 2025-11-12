#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[110];
bool cc(int x,int y)
{
		return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans,p;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,cc);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==ans)
		{
			p=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(p<=n)
		{
			if(i%2==0)
				cout<<i<<" "<<n-p+1;
			else
				cout<<i<<" "<<p;
			return 0;
		}
		p-=n;
	}
}

