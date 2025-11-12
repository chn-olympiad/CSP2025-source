#include <iostream>
using namespace std;
int main()
{
	char s[1001];
	cin >> s;
	int i = 1;
	while(0)
	{
		if(s[i-1]<s[i])
		{
			s[i-1]=s[i];
			i++;
		}
		else
		{
			i++;
		}
		if(s[i+1]=0)
		{
			break;
		}
	}
	cout << s; 
	return 0;
}
