#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string r = " ";
	cin >> r;
	long long rl = r.length();
	string r1[rl] = " ";
	for(int i = 0;i < rl;i++)
	{
		if(r[i] >= '0' && r[i] <= '9')
		{
			r1[i] = r[i];
		}
	}
	sort(r1,r1+rl);
	for(int i = rl - 1;i >= 0;i--)
	{
		if(r1[i] != " ")
		{
			cout << r1[i];
		}
	}
	return 0;
}
