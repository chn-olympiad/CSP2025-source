#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(char val:s)
		if(val>='0'&&val<='9')
		a.push(val-'0');
	while(!a.empty())
	{
		cout << a.top();
		a.pop();
	}
	return 0;
}
