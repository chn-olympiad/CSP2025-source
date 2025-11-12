#include <bits/stdc++.h>
using namespace std;

int m=0,a[10000005];
char s;
int string1=123456789;
int shu(int s)
{
	m=string.size(s);
	for(int i=1;i<=m;i++)
	{
		if(a[i]==string1)
		{
			sort(a[1],a[i],a[i+1]);
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
    cin>>s;
    cout<<shu(s);
	return 0;
}