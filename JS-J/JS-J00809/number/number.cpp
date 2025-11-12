#include<bits/stdc++.h>

using namespace std;

long long stat[10];
string str;

int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>str;

	for(int i = 0 ; i < str.length() ; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			stat[str[i] - '0']++;
			//cerr<<str[i] - '0';
		}
	}
	//cerr<<str;
	for(int i = 9 ; i >= 0 ; i--)
	{
		for(int j = 1 ; j <= stat[i] ; j++)
		{
			cout<<i;
		}
	}
	return 0;
} 