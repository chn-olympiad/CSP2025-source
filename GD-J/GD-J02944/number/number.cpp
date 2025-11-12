#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,res;int x=0;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[x]=s[i];
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--)
		res+=a[i];
	cout<<res;
	return 0;
} 
