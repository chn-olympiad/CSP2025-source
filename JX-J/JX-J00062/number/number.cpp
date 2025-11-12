#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000001],j=0,l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if((s[i]>='0')&&(s[i]<='9'))
		{
			n[j]=s[i]-'0';
			j++;
		}
	}
	sort(n,n+j);
	for(int i=j-1;i>=0;i--)
	{
		cout<<n[i];
	}
	return 0;
}
