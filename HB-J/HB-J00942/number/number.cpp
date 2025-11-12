#include <bits/stdc++.h>
using namespace std;
string a;
int book[105]={0};
int len=0,t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(a[t]!='\0')
	{
		 len++;
		 t++;
	}
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]>='0'&&a[i]<='9') book[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=book[i];j++) cout<<i;
	}
	return 0;
}
