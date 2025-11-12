#include <bits/stdc++.h>
using namespace std;
void 
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,a[10005],cnt=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n<=3&&a[1]+a[2]>a[3])
	{
		cnt++;		
	}
	return 0;
}
