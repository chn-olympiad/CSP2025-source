#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000001],t=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len=s.size();
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
		  a[i]=s[i]-'0';
		  t++;
	    }
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--)
	  cout << a[i];
	return 0;
}
