#include <iostream>
#include <string>
using namespace std;

int box[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			box[int(s[i] - '0')]++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= box[i]; j++)
		{
			cout << i;
		}
	}
	cout << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
