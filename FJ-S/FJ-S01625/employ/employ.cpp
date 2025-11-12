#include <bits/stdc++.h>
using namespace std;
int c[501];
const int x=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	long long cnt=1;
	for(int i=1;i<=n;i++)
	{
		cnt*=i;
		cnt=(cnt+x)%x;
	}
	cout<<cnt;
	return 0;
}
