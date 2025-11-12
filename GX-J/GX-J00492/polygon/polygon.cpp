#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
long long n,a[10010],ans,hdk;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]+a[2]+a[3]>a[3]*2)ans++;
	cout<<ans;
	return 0;
}
