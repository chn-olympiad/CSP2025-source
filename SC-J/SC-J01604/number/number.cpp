#include <bits/stdc++.h>
using namespace std;
string s;
int ans[11];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char x:s)
		if('0'<=x&&x<='9')
			ans[x-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=ans[i];j++)cout<<i; 
	return 0;
}