#include<bits/stdc++.h>
using namespace std;
int a[150];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int k=n*m;
	cin >> a[0];
	int t=0;
	for(int i=1;i<k;i++)
	{
		cin >> a[i];
		if(a[i]>a[0])
		{
			t++;
		}
	}
	t++;
	int l=t/n;
	if(t%n!=0) l++;
	if(l%2==0)
	{
		cout << l << " " ;
		if(l*n==t)
		{
			cout << n;
		}
		else
		{
			cout << n-(t - (l-1)* n)+1;
		}
	}
	else{
		cout << l << " " ;
		if(l*n==t)
		{
			cout << n;
		}
		else
		{
			cout << t - (l-1)* n;
		}
	}
	return 0;
}
