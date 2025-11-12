#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int a[5005],n,now,s;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	
	now=a[1]+a[2]+a[3];
	if(now>a[3]*2&&now>a[2]*2&&now>a[1]*2)s++;
	
	cout<<s;
	return 0; 
}
