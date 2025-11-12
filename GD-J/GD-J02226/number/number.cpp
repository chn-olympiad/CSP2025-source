#include<bits/stdc++.h>
using namespace std;
int n=0,a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++n]=s[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	bool ok=false;
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=0) ok=true;
		if(ok==true) cout<<a[i];
	}
	if(ok==false) cout<<0;
	return 0;
}
