#include <string>
#include <fstream>

using namespace std;

string s;
int mp[15];

ifstream cin("number.in");
ofstream cout("number.out");

int main()
{
	
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			mp[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < mp[i]; j++)
		{
			cout << i;
		}
	}
	
	cin.close();
	cout.close();
	
	return 0;
}
