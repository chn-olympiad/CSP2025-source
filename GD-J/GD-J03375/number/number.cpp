#include<bits/stdc++.h>
using namespace std;
int vis[11];
string l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> l;
	for(int i=0;i<l.size();i++)
	{
		int x = l[i] - '0';
		if(x >= 0 && x <= 9)
		{
			vis[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(vis[i]--)
		{
			cout << i;
		}
	}
	return 0;
}
