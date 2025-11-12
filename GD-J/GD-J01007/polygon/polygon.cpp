#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5005];
long long q[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];	
	} 
	sort(a+1,a+1+n);
	q[1]=a[1];
	if(n==3)
	{
		for(int i=2;i<=n;i++)
		{
			q[i]=q[i-1]+a[i];
		}
		if(q[n]>2*a[n])
			cout << 1;
		else cout << 0;
	}
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
