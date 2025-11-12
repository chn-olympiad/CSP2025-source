#include<bits/stdc++.h>
using namespace std;
string str;
int n[1000005],temp,s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0'&&str[i]<='9')
			n[temp++]=str[i]-'0';
	sort(n,n+temp,cmp);
	for(int i=0;i<temp;i++)
		cout<<n[i];
	return 0;
}