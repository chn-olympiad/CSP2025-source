#include<bits/stdc++.h>
#define ll long long
#define __ 998244353
using namespace std;
string s;
int n,a[505],ans=1,m;
int main()
{
	int i;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		ans=(ans*i)%__;
	cout<<ans;
	return 0;
}