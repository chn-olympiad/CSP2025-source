#include <bits/stdc++.h>
using namespace std;
string s;
long long n,m,c[505],ans=1;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='0')
		{
			return 0;
		}
	}
	for (int i=n;i>=1;i--){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}
