#include <bits/stdc++.h>
using namespace std;
string a;
int b[100005];
long long num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (int i=0;i<sizeof(a);i++)
	{
		if (a[i]=="1")
		{
			b[i]=1;
		}
		else if (a[i]=="2")
		{
			b[i]=2;
		}
		else if (a[i]=="3")
		{
			b[i]=3;
		}
		else if (a[i]=="4")
		{
			b[i]=4;
		}
		else if (a[i]=="5")
		{
			b[i]=5;
		}
		else if (a[i]=="6")
		{
			b[i]=6;
		}
		else if (a[i]=="7")
		{
			b[i]=7;
		}
		else if (a[i]=="8")
		{
			b[i]=8;
		}
		else if (a[i]=="9")
		{
			b[i]=9;
		}
		else if (a[i]=="0")
		{
			b[i]=0;
		}
	}
	sort(b+1,b+a.sizeof()+1);
	for (int i=0;i<a.sizeof();i++)
	{
		if (b[i]!='0')
		{
			num+=b[i]*(10*i+1);
		}
	}
	cout<<num;
	return 0;
}
