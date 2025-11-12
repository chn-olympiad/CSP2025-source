#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;
int a[N];

int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","u",stdout);
	string s;
	cin >> s;
	string ans = "";
	int cur = 0;
	for(int i = 0;i < s.size();i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			cur++;
			a[cur] = (s[i] - '0');
		}
	}
	sort(a + 1,a + cur + 1);
	for(int i = cur;i >= 1;i--)
	{
		cout << a[i];
	} 
	return 0;
	//fclose(stdin);
	//fclose(stdout);
}
