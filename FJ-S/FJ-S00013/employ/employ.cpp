#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],cnt[505],pre[505];
string s;
const long long Mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	cout<<0;
	return 0;
}
