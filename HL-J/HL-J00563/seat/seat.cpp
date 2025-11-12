#include<bits/stdc++.h>
using namespace std;
int n,m,a,r,h=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a;
		if(a>r)h++;
	}
	cout<<((h-1)/n)+1<<' ';
	cout<<(1-(2*(((h-1)/n)%2)))*(((h-1)%n)+1)+((n+1)*(((h-1)/n)%2));
	return 0;
}