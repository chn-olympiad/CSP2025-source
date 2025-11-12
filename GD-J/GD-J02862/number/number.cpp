#include<bits/stdc++.h>
using namespace std;

long long num[1000006],x;
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	for(long long i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			++x;
			num[x] = s[i] - '0';
		}
	}
	
	sort(num + 1,num + 1 + x);
	
	for(long long i = x; i > 0; i--)
	{
		printf("%lld",num[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
