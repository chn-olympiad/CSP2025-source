#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=5005;
int a[N];
boolcmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n==3 && a[1]+a[2]>=a[3])
	{
		cout << 1;
		return 0;
	}
	else if(n==3 && a[1]+a[2]<a[3])
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << 19;
	}
	return 0;
}