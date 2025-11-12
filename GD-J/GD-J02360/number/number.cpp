#include <bits/stdc++.h> 
using namespace std;

int main()
{
	long long numb[12] = {0};
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int slen = s.size();
	for(int i = 0;i < slen;i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			numb[s[i] - '0']++;
		}
	}
	
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 0;j < numb[i];j++)cout<<i;
	}

	
	return 0;
}
