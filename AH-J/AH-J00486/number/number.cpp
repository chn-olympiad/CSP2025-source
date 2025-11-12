#include<bits/stdc++.h>
using namespace std;
string str,str2;
long long len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	len = str.size();
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			str2 += str[i];
		}
	}
	sort(str2.begin(),str2.end(),greater<char>());
	cout<<str2;
	return 0;
}
