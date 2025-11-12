#include<bits/stdc++.h>
using namespace std;
long long n,c=0,a[5005],b[5005],ans=0;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <=n;i++)
	{
		cin >> a[i];
	}
	b[2]=1;
	for(int i = 3; i <= n; i++)
	{
		b[i]=i-1;
	}
	for(int i = 3;i<=n;i++)
	{
		ans+=b[i];
	}
	cout << ans;
	return 0;
}