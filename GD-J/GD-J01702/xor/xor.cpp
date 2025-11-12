#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;cin >> n;int num[n+1]={0};vector<vector<long long> >dp(n+1,vector<long long>(n+1,0));
	for(int i = 1;i<=n;i++)
	{
		cin >> num[i];
		dp[i][1] = num[i];
	}
	cout << 0;

}
