#include<bits/stdc++.h>
using namespace std;
int a[1000],b=0,n,i,c,d;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout); 
string s;
int n;
getline(cin,s);
for(int i=0;i<s.size();i++)
{
	if(isdigit(s[i]))
	{		
	s[i]=(s[i]-'0')*10;
	b=s[i]/10;
	cout<<b;
	}
}
return 0;
}
