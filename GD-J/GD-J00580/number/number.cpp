#include<bits/stdc++.h>
using namespace std;
int a[15];
string str;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a)),cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0'&&str[i]<='9') a[int(str[i]-'0')]++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<a[i];j++) cout<<i;
	return 0;
 } 
