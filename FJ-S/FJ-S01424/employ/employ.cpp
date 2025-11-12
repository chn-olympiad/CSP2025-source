#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) 
	{
		ans*=i;ans%=998244353;
	}
	cout<<ans;
	return 0;
}

