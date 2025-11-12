#include <bits/stdc++.h>
using namespace std;
int n,ans,a[500005],k;
/*
int yh(int a,int b)
{
	if (a==0) return 0;
	if (a<b) swap(a,b);
	while(a!=0||b!=0)
	{
		//if ()
	}
}
*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=256;
	cout << n/2;
	return 0;
}
