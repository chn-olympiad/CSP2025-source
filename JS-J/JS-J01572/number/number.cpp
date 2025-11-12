#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	int a = 1;
	int n;
	string s;
	char b[1000005];
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    n = s.size();
    for(int i = 0;i < n;i++)
    {
		if(s[i] <= '9' && s[i] >= '0')
		{
			b[a] = s[i];
			a++;
		}
	}
	sort(b + 1,b + a + 1);
	for(int i = a;i >= 1;i--)
	{
		cout << b[i];
	}
    return 0;
}
