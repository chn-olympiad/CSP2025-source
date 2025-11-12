#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
bool cmp(int b1,int b2)
{
	return b1 >= b2;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int x = s.size();
	int j = 0;
	for(int i = 0;i < x;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[j + 1] = s[i] - '0';
			j++;
		}
	}
	sort(a + 1,a + j + 1,cmp);
	for(int i = 1;i <= j;i++) printf("%d",a[i]);
	return 0;
}
