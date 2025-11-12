#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,a[4];
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]+a[2]<=a[3]||n<3)
	{
	  cout<<'0';
    }
	if(a[1]+a[2]>a[3])
	{
	  cout<<'1';
    }
	return 0;
}
