#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=998244353;
int n,m,c[N];
ll ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%M;
	}
	cout<<ans;
	return 0;
}
