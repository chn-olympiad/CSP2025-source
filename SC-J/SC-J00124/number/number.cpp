#include<bits/stdc++.h>
using namespace std;
int i,j,a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(i=0;i<s.size();i++)
	if(isdigit(s[i]))
	a[s[i]-'0']++;
	for(i=9;i>=0;i--)
	if(a[i]!=0)
	for(j=0;j<a[i];j++)
	printf("%d",i);
	return 0;
} 