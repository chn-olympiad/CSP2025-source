#include<bits/stdc++.h>
using namespace std;
string str;
int a[1000010],v=0;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in" ,"r",stdin );
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(48<=str[i]&&str[i]<=57)
		a[v++]=str[i]-48;
	}
	sort(a,a+v,cmp);
	for(int i=0;i<v;i++)
	cout<<a[i];
}
