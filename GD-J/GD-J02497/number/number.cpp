#include<bits/stdc++.h>
using namespace std;

int a[1000006]; 

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int zh = 0;
	string s;
	cin >> s;
	for (int i = 0;i <= s.size() - 1;i ++)
	{
		if (s[i] >= '0' && s[i] <= '9') 
		{
			zh ++;
			a[zh] = int(s[i]- '0');
		}
	}
	sort (a + 1,a + zh + 1,cmp);
	for (int i = 1;i <= zh;i ++)
	{
		printf("%d",a[i]);
	}
} 
