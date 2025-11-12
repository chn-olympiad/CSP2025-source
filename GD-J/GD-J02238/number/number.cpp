#include<bits/stdc++.h>
using namespace std;

string s;
int a[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> s;
	
	for(int i = 0;i < s.size();i ++)
	{
		if(isdigit(s[i]))
		{
			a[s[i] - '0'] ++;
		}
	}
	
	for(int i = 9;i >= 0;i --)
	{
		if(a[i] != 0)
		{
			for(int j = 1;j <= a[i];j ++)
			{
				cout << i;
			}
		}
	}
	
	fclose(stdin), fclose(stdout);
	return 0;
}

