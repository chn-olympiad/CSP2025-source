#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n,m;
int a[600];
string s;
int ans,cnt;
int answer=1; 
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) answer=answer*i%MOD;
	cout<<answer;
	return 0;
}

