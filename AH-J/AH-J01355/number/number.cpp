#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
string s;
int a[N];
int tot;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("number.in","r",stdin);
	freopen("number.out","w", stdout);
	cin>>s;
	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		if (isdigit(s[i])) 
		{
			a[++tot] = s[i] - '0';
		}
	}
	sort (a + 1,a + tot + 1);
	for (int i = tot; i >= 1; i--)
	{
		cout <<a[i];
	}
	return 0;
}
