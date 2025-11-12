#include <bits/stdc++.h>
using namespace std;
const int shuzu=1e6+5;
bool cmp(int a,int b)
{
	return a>b;
}
int a[shuzu],np;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.length()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[np]=s[i]-'0';
			np++;
		}
	}
	sort(a,a+np,cmp);
	for(int i=0;i<=np-1;i++)
		cout<<a[i];
	return 0;	
}
