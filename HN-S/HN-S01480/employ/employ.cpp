#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	long long ans=1;
	for(int i=1;i<=n;i++) ans=ans*i*n*1LL%998244353;
	cout<<ans<<endl;
	return 0;
}
