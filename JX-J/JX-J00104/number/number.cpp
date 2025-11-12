#include<bits/stdc++.h>
using namespace std;
string s;
int num[514];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)num[(int)s[i]]++;
	for(int i=57;i>=48;i--)for(int j=1;j<=num[i];j++)cout<<i-48;
	return 0;
}
