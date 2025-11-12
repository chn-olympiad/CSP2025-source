#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
string s;
int a[1000000+10],t=0;
bool cmp(int x,int y)
{
	if(x!=y)
	  return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l-1;i++)
	  if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
	  {
		t++;
		a[t]=s[i]-'0';
	 }
	if(t==1)
	{
	  cout<<a[1];
	  return 0;
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	  cout<<a[i];
	return 0;
}
