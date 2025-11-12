#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
const int M = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m ;
	string s;
	cin >> s;
	int c[N];
	for(int i = 1; i <= n ; i ++)
	{
		cin >> c[i];
	}
	int ans = 1;
	for(int i = 1; i <= n ; i++)
	{
		ans = (ans*i)%M;
	}
	cout<<ans; 
	return 0;
}