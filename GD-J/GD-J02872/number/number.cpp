#include <bits/stdc++.h>
using namespace std;
int sz[1000005];
bool cmp(int &a,int &b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int id = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			sz[++id] = s[i] - '0';
	}
	sort(sz+1,sz+id+1,cmp);
	if (sz[1] == 0)
	{
		cout << 0;
	}
	else
	{
		for (int i = 1;i <= id;i++)
			cout << sz[i];
	}
	return 0;
} 
