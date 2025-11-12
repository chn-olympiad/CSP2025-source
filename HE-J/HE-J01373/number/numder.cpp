#include<bits/stdc++.h>
using namespace std;
char a;
int b[1005];
int main()
{
	freopen("number.in","r"stdin);
	freopen("number.out","w"stdout);
	string a;
	for(int i=0;i<=1005;i++)
	{
		if(1<=a[i]<=9)
		{
			a[i]=b[i];
		}
	}
	sort(b,b+1005);
	for(int i=0;i<=1005;i++)
	{
		cout<<b[i];
	}
	return 0;
}
