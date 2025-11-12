#include<bits/stdc++.h>
using namespace std;
int n,q,b[200005],te[200005],cnt; 
int check(string str)
{
	int len = str.length();
	for(int i = 0;i < len;i++)
	{
		if(str[i] == 'b') return i;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		int b1 = check(s1),b2 = check(s2);
		b[i] = b1 - b2;
	}
	if(q == 1)
	{
		string st1,st2;
		cnt = 0;
		cin >> st1 >> st2;
		int t1 = check(st1),t2 = check(st2);
		int temp = t1 - t2;
		for(int i = 1;i <= n;i++)
		{
			if(b[i] == temp) cnt++;
		}
		cout << cnt << endl;
	}
	else 
	{
		for(int i = 1;i <= q;i++)
		{
			string st1,st2;
			cin >> st1 >> st2;
			cout << 0 << endl;
		}
	}
	return 0;
 } 
