#include<bits/stdc++.h>
using namespace std;
int a[505];
int MOD=998244353,n,m;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int d=n*(n-1);
	cout<<d%MOD;
	
	return 0;
}


