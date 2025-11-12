#include<bits/stdc++.h>
using namespace std;

int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=i;
			break;
		}
	}
	cout<<r/n+1<<" ";
	if((r/n+1)%2==0)
	{
		cout<<n-r+1;
	}
	else
	{
		r%=n;
		cout<<r;
	}
	return 0;
}