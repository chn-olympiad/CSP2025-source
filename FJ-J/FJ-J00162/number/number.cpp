#include<bits/stdc++.h>
using namespace std;
int num[512];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0,sze=s.size();i<=sze;i++)
		num[int(s[i])]++;
	for(int i='9';i>='0';i--)
		for(int j=1;j<=num[i];j++)
			putchar(i);
	return 0;
}
//66666666666666