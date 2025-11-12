#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int C=998244353;
vector<int>vect;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	string str;cin>>str;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		vect.push_back(x);
	}
	int res=1;
	for(int i=1;i<=n;i++)
	{
		res=(res*n%C)%C;
	}
	cout<<res;
 } 
