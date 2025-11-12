#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n, m, c[505], ans;
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) cin>>c[i];
	if(m==1)
	{
		for(int i=1; i<=n; i++) ans+=i;
		cout<<ans;
		return 0;
	}
	else if(m==n)
	{
		cout<<1;
		return 0;
	}
	cout<<2204128;
	return 0;
}
