#include <bits/stdc++.h>
using namespace std;
int a[128];
char ch;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(cin>>ch)
		a[(int)ch]++;
	for(char i = '9';i >= '0';i--)
		for(int j = 1;j <= a[i];j++)
			printf("%c", i);
	return 0;
}
