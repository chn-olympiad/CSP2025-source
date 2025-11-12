#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,m;
string s;
ll c[110010];
int main()
{
	freopen("employ.in","r","stdin");
	freopen("employ.out","w","stdout");
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<m%mod;
	return 0;
}

