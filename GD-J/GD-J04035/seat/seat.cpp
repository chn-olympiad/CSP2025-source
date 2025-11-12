#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105],x,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	k=n*m+1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				k--;
				if(a[k]==x)
				{
					cout << i <<" "<< j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				k--;
				if(a[k]==x)
				{
					cout << i <<" "<< j;
					return 0;
				}
			}
		}
	}

	return 0;
}
/*
Rp++
T2 too water~
*/
