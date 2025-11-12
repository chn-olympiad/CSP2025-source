#include<bits/stdc++.h>
using namespace std;
long long Q,k,n,m,a[500005],s[500005],ans;
string st;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
	else cout<<0;
	return 0;
}
