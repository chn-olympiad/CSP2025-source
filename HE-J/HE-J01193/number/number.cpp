#include <bits/stdc++.h>
using namespace std;
int a[1000010],x=0;
string s;
bool cmp(int n,int m)
{
	return n>m;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x+1,cmp);
	for(int i=0;i<x;i++)
	{
		cout<<a[i];
	}
	return 0;
} 
