#include<bits/stdc++.h>
using namespace std;
int a[10001],w=0;
char n[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freoprn("number.out","w",stdout);
	cin>>n;
	int len=strlen(n);
	for(int i=0;i<=len;++i)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[w]=n[i]-'0';
			w++;
		}
	}
	sort(a,a+w);
	for(int i=w-1;i>=0;--i)
	{
		cout<<a[i];
	}
	return  0;
 } 
 
