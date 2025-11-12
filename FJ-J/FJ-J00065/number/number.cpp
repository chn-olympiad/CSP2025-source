#include <iostream>
#include <cstring>
using namespace std;

int cnt[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;s[i];i++)
	{
		if(isdigit(s[i]))
		{
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(cnt[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}
