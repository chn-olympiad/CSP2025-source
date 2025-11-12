#include<bits/stdc++.h>
#define endl '\n'
#define LX long long
using namespace std;
vector<LX> a(10, 0);
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	for(auto lx : s)
	{
		if(lx >= '0' && lx <= '9')
		{
			a[lx - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--)
		for(LX j = 1; j <= a[i]; j++)
			cout << i;
	cout << endl;
	return 0;
}
