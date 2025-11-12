#include<bits/stdc++.h>
using namespace std;
string a[1000005];
int b=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
		{
			a[b]=s[i];
			b++;
		}
	}
	sort(a,a+b);
	for(int i=b-1;i>=1;i--)
	{
		cout<<a[i]; 
	}
	return 0;
}
