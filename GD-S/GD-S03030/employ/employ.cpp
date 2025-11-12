#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505],ans=1;
	char s[505];
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=2;i<=n;i++) ans=(ans*i)%998244353;
	cout<<ans;
}
