#include <bits/stdc++.h>
using namespace std;
int n,m,x,permu,modd;
int a[1005];
bool cmp(int j,int k)
{
	return j>k;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	x=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x)
		{
			permu=i;
			break;
		}
	if(permu%n==0)
	{
		if((permu/n)%2==1)
			cout << permu/n << " " << n;
		else cout << permu/n << " " << 1;
	}
	else
	{
		if((permu/n)%2==1)
			cout << permu/n+1 << " " << n-(permu%n-1);
		else cout << permu/n+1 << " " << 1+(permu%n-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
