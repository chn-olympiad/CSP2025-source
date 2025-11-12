#include<bits/stdc++.h>
using namespace std;
string s;
string p;
int n;
const int N=1e6+9;
int a[N];
int main()
{
	freeopen("number.in","r",stdin);
	freeopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			p+=s[i];
		}
	}
	for(int i=0;i<p.size();i++)
	{
		a[i]=p[i]-'0';
	}
	sort(a,a+p.size());
	for(int i=p.size()-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}











