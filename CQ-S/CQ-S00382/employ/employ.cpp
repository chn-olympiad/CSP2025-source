#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n;
long long s=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=n;i>=1;i--)
	{
		s*=i;
		s%=MOD;
	}
	cout<<s;
	return 0;
}
