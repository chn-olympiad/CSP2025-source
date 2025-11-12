#include <bits/stdc++.h>

using namespace std;

//number.cpp

string str;
int a[1000005];
int cnt = 0;

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> str;
	
	for(int i = 0;i < str.length();i ++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			a[++ cnt] = str[i] - '0';
		}
	}
	
	sort(a + 1,a + cnt + 1,cmp);
	
	if(a[1] == 0) cout << 0;
	else
	{
		for(int i = 1;i <= cnt;i ++)
		{
			cout << a[i];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
