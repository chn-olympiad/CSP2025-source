#include <iostream>
#include <map>
using namespace std;
string st;
int mp[65];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> st;
	for(char c : st)
	{
		if(isdigit(c))
		{
			mp[c]++;
		}
	}
	for(char c = '9';c >= '0';c--)
	{
		for(int i = mp[c];i >= 1;i--)
		{
			cout << c;
		}
	}
	cout << endl; 
	return 0;
}
