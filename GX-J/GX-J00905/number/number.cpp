#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a[1000010],tot=1,flag;
int flag1;
string s;
bool cmp(int u,int v)
{
	return u>v;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0' && s[i]<='9') 
		{
			flag1=1;
			if(s[i]!='0') flag=1;
			a[tot++]=s[i]-'0';
		}
	sort(a+1,a+tot,cmp);
	if(!flag || !flag1) {cout<<0; return 0;}
	for(int i=1;i<tot;i++) cout<<a[i];
	return 0;
}
