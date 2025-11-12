#include <bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,m;
string s;
int c[510];
long long ans;
bool checkA()
{
	for (int i=0;i<n;i++) if (s[i]=='0') return false;
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)cin>>c[i];
	if (checkA())
	{
		ans=1ll;
		for (int i=n;i>=1;i--)
		{
			ans=(ans*i*1ll)%N;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
3 2
111
1 1 2
*/
