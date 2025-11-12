#include<bits/stdc++.h>
using namespace std;
char a[1000010],t[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=1000010;i++)
	{
		if(a[i]>='0' && a[i]<='9')
			t[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int l=1;l<=t[i];l++)
			cout<<i;
	return 0;
}