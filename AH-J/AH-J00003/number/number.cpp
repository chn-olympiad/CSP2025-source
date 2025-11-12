#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[100010],x=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x++]=s[i]-'0';
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--) cout<<a[i];
	return 0;
}
