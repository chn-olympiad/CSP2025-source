#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if((a[1]<=a[2]+a[3] and a[1]>=abs(a[2]-a[3]))or(a[2]<=a[1]+a[3] and a[2]>=abs(a[1]-a[3])) or (a[3]<=a[2]+a[1] and a[3]>=abs(a[2]-a[1])))
	{
		cout<<1;
	}
	return 0;
}