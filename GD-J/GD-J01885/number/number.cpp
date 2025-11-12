#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000010]={};
	int b[12]={};
	cin>>a;
	int i=0;
	for(;i<1000010;i++)
	{
		if(a[i]==' ') break;
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-'0']++;
		}
	}
	i=9;
	for(;i>=0;i--)
	{
		while(b[i]>0)
		{
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
