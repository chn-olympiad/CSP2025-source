#include <bits/stdc++.h>
using namespace std;

int b[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	string s;
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		b[s[i]-'0']++;
	}
	bool flag = 0;
	for(int i = 9; i >= 0; i--)
	{
		if(i==0&&flag==0){
			cout << 0;
			continue;
		}
		while(b[i]>0)
		{
			cout << i;
			b[i]--;
			flag=1;
		}
	}
}
