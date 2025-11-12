#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int hang(int x)
{
	if((x+n-1)/n%2==1)
	{
		if(x%n==0)	return n;
		else		return x%n;
	}
	else
	{
		if(x%n==0)	return 1;
		else		return n-(x%n)+1;
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s)
		{
			cout<<(i+n-1)/n<<' ';
			cout<<hang(i);
			break;
		}
	return 0;
}
