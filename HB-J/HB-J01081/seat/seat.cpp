#include<bits/stdc++.h>
using namespace std;
int a[10001];
int s[100][100];
bool f(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int ans;
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,f);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==ans)
		{
			int c=i/n;
			if(i%n!=0)
			{
				c++;
			}
			int f=i%c;
			if(c%2==0)
			{
				f=m-f+1;
			}
			if(i%n==0)
			{
				f=n;
			}
			cout<<c<<" "<<f<<endl;
		}
	}
	return 0;
}
