#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[(int)(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;--i)
	{
		while(a[i])
		{
			printf("%d",i);
			a[i]--;
		}
	}
	return 0; 
}