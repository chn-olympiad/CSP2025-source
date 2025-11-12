#include <iostream>
using namespace std;
string s;
int box[300];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
		box[s[i] - '0']++;
	for(int i = 9 ; i >= 0 ; i--)
		for(int j = 1 ; j <= box[i] ; j++)
			cout << i;
	return 0;
}
