#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],place=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int score=a[1];
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>score)
		{
			place++;
		}
	}
	if(((place-1)/n+1)%2==1)
	{
		if(place%n==0)
		{cout<<place/n<<n;}
		else
		{cout<<place/n+1<<place%n;}
	}
	else
	{
		if(place%n==0)
		{cout<<place/n<<1;}
		else
		{cout<<place/n+1<<n-(place%n)+1;}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
