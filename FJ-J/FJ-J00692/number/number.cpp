#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],x;
bool mm(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]<='9'&&s[i]>='0')
			a[++x]=s[i]-'0';
	sort(a+1,a+1+x,mm);
	for(int i=1;i<=x;i++)
		printf("%d",a[i]);
	return 0;
}