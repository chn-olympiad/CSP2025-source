#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
ll ans[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string S;
	cin>>S;
	for(int i=0;i<S.size();i++)
	{
		if('0'<=S[i]&&S[i]<='9')
		{
			ans[S[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(ans[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}
