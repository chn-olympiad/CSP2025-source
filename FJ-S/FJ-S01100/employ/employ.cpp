#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n;i++)
	ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
}

