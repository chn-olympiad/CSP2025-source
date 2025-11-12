#include <bits/stdc++.h>
using namespace std;
int n,m,a[120];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	int s= a[1];
	for(int i=1;i<n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
//	cout << a[1] << " " << s << " ";
	for(int i=1;i<=n*m;i++)
	{
		if(a[i] == s)
		{
//			cout << i;
			if(i!=n && i!=m)
			{
				cout << i/m << " " << i/n;
				return 0;
			}else if(i!=n && i == m)
			{
				cout << m << " " << i/n; 
				return 0;
			}else
			{
				cout << i/m << " " << n;
				return 0;
			}
		}
	}
	return 0;
}
