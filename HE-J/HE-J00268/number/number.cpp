#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	long long m=0,ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
        	a[m]=s[i];
        	m++;
        	ans++;
		}
	}
	char x='0';
	int n=0;
	for(int j=0;j<ans;j++)
	{
		x='0';
		for(int i=0;i<ans;i++)
		{
			if(x<a[i])
			{
				x=a[i];
				n=i;
			}
		}
		cout<<x;
		a[n]='0';
	}
	return 0;
}
