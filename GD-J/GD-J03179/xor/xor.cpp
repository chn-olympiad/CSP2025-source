#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int a[500005], suf[500005];
set<int> s; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, m, i, sum = 0, ans = 0;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
		cin >> a[i];
	for(i = n; i; i--)
		suf[i] = suf[i+1] ^ a[i];
	for(i = 1; i <= n; i++)
	{
		s.insert(suf[i]);
		if(s.count(m ^ suf[i+1]))
		{
			s.clear();
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
