#include<bits/stdc++.h>
using namespace std;
string s;
int a[114514],l,k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	l=s.size()-1;
	for(int i=0;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			a[k]=s[i]-48;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	{
		cout<<a[i];
	}
}
