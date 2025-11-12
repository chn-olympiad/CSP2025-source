#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

string s;
int len;
int a[N];

bool cmp(int a1 , int a2)
{
	return a1 > a2;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0 ; i < s.length() ; i ++)
	{
		int temp = s[i] - '0';
		if(temp >= 0 && temp <= 9)
		{
			a[++len] = temp;
		}
	}
	sort(a + 1 , a + len + 1 , cmp);
	for(int i = 1 ; i <= len ; i ++)
	{
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
