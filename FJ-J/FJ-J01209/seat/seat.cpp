#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[150],xs=0,ys=0,shu=0;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> s[i];		
	}
	int x = s[1];
	sort(s+1,s+(n*m)+1);
	for(int i = 1;i <= n*m;i++)
	{
		if(s[i]==x)
		{
			shu = n*m-i+1;
			break;
		}
	}
	xs = ceil(shu*1.0/n);
	if(xs%2==1)
	{
		ys = shu%n;
	}
	else
	{
		ys = n - (shu%n)+1;
	}
	if(ys==0&& x % 2 == 1)
	{
		ys = n; 
	}
	cout << xs << " " << ys;
	return 0;
}
