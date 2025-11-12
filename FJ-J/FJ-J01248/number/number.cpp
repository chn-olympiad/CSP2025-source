#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a[n++]=s[i]-'0';
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)cout<<a[i];
	return 0;
}

