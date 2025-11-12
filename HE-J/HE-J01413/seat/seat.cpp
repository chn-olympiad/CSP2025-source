#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,id;
int a[105];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n>>m;
	int t=n*m;
	int s;
	for(int i=1;i<=t;i++)
		std::cin>>a[i];
	s=a[1];
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)
		if(a[i]==s)
			id=i;
	int h;
	if(id%n!=0)
	{
		cout<<id/n<<' ';
		h=id/n;
	}
	else
	{
		cout<<id/n+1<<' ';
		h=id/n+1;
	}
	if(h%2!=0)
	{
		if(id%m!=0)
			cout<<id/m+1;
		else
			cout<<id/m;
	}
	else
		cout<<id/m+1;
	return 0;
}
