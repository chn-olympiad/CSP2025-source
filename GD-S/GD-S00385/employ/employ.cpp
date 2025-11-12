#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long

using namespace std;

const int N = 510;
const ll MOD = 998244353;

bool s[N];
int c[N],p[N],n,m;
ll ans = 0;

void Solve()
{
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		if(i - 1 - cnt < c[p[i]])
		{
			if(s[i]) cnt++;
		}
	}
	if(cnt >= m) ans++;
	return;
}

bool CheckA()
{
	for(int i = 1;i <= n;i++) if(!s[i]) return 0;
	return 1;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i;
	char ch;
	cin>>n>>m;
	for(i = 1;i <= n;i++)
	{
		cin>>ch;
		s[i] = ch - '0';
	}
	for(i = 1;i <= n;i++) cin>>c[i];
	for(i = 1;i <= n;i++) p[i] = i;
	do
	{
		Solve();
	}while(next_permutation(p + 1,p + n + 1));
	cout<<ans;
	return 0;
}
