#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005];
char s[100005];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int e = 1;
	cin >> s;
	int n = strlen(s);
	for (int i = 0;i < n;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[e] = int(s[i]) - 48;
			e++;
		}
	}
	sort(a + 1,a + e,cmp);
	for (int i = 1;i < e;i++)
	{
		cout << a[i];
	}
	return 0;
} 
