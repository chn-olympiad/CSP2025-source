#include<bits/stdc++.h>
using namespace std;
string s,a="";
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a+=s[i];
		}
	}
	sort(a.begin(),a.end());
	int m=a.size();
	for(int i=m-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
