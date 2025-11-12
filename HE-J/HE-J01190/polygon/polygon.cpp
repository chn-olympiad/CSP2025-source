#include <bits/stdc++.h>
#include <string>
using namespace std;
long long b=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	int a[n+5];
	cin>>a[1];
	int max=a[1];b+=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];if(max<a[i])max=a[i];b+=a[i];
	}
	if(b>2*max)cout<<1;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	  return 0;
}
