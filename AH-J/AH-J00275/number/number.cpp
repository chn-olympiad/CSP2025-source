#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
int l;
int a[MAXN],t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(isdigit(s[i])) a[++t]=s[i]-'0';
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++) cout<<a[i];
	return 0;
}
