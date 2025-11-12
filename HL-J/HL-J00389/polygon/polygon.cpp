#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	
	int n,sum=0;
	cin >> n;
	if(n<3) 
	{
		cout << 0;
		return 0;
	}
	int a[n];
	for(int i=0;i<3;i++) cin >> a[i];
	int maxv=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>maxv) maxv=a[i];
	}
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	if(sum<=maxv*2)
	{
		cout << 0;
	}
	else cout << 1;
	return 0;
}
