#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
char r[1000000];
int n;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",cin);
	freopen("number.out","w",cout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))r[n++]=(char)s[i];
	}
	sort(r,r+n,cmp);
	for(int i=0;i<n;i++)cout<<r[i];
} 
