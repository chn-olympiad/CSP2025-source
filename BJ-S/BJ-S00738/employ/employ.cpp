#include <bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],ans=1;
string s;
vector<int> v;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
