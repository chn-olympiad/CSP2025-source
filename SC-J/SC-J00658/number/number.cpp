#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],n=0;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			a[++n]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
} 