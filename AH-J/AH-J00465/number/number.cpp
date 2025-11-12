#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int b[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	
	int len = s.size();
	
	for(int i = 0;i <= len-1;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			int a = s[i] - '0';
			b[a]++;
		}
	}
	
	for(int i = 9;i >= 0;i--)
	{
		if(b[i] != 0)
		{
			for(int j = 1;j <= b[i];j++)
			{
				cout << i;
			}
		}
	}
	
	return 0;
}
