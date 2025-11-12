#include<bits/stdc++.h>
using namespace std;
char c;
string s;
int n,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=1;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
		{
			a[n]=s[i]-'0';
			++n;
		}
	sort(a+1,a+n+1);
	if(a[n]==0)
	{
		cout<<0;
		return 0;
		}
	for(int i=n;i>=2;i--)
		cout<<a[i];
	return 0;
}
