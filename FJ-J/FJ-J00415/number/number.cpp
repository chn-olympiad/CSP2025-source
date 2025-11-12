#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int cnt[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(char c:s)
		if(c>='0'&&c<='9')cnt[c-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=cnt[i];j++)
			cout<<i;
	return 0;
}
