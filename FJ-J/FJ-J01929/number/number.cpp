#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
int a[N],tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			tot++;
			a[tot]=str[i]-48;
		}
	}
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
