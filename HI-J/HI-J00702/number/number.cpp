#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = 1;
	int a[1000005];
	int benben[10]={0};
	int len = s.size();
	for(int i = 0;i < len;i++)
	{
		if (s[i] <= 'z' && s[i] >= 'a')
		{
		    s[i] = '/';
	    }
	}
	for(int i = 0;i < len;i++)
	{
		if (s[i] != '/')
		{
		    a[n] = s[i];
		    a[n] = a[n]-48;
		    benben[a[n]]++;
	    }
	}
	for(int i = 9;i >= 0;i--)
	{
		while(benben[i] != 0)
		{
		    cout << i;
		    benben[i]--;
		}
	}
	return 0;
}
