#include <bits/stdc++.h>
using namespace std;
string n;
string m , s;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> n;
	for (int i = 0;i < n.size();i++)
	{
		if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9' || n[i] == '0')
		{
			m[i] = n[i];
			cout << m[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
