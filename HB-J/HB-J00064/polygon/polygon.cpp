#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polgyon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==3)
	{
		int t=a[0]+a[1]+a[2];
		if(a[2]*2>=t)cout<<0;
		else cout<<1;
	}
    return 0;
}
