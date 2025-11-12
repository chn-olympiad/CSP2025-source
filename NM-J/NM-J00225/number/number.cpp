#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
string n;
int k[1000010];
int t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n.size();i++)
	{
		if('0' <= n[i] && '9' >= n[i])
		{
			k[t] = n[i] - '0';
			t++;
		}
	}
	sort(k,k + t);
	for(int i = t - 1;i >= 0;i--) 
	{
		cout << k[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
