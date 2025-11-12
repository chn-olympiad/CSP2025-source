#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 510;
int n,m,ans,cnt,sum,c[N],a[N];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		a[i] = i;
	}
	do
	{
		cnt = sum = 0;
		for(int i = 1;i <= n;i++)
		{
			if(s[i - 1] == '0' || cnt >= c[a[i]])
				cnt++;
			else
				sum++;
		}
		if(sum >= m)
			ans++;
	}while(next_permutation(a + 1,a + 1 + n));
	cout << ans;
	return 0;
}

