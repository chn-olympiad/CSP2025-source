#include<bits/stdc++.h>
using namespace std;
int a[1000010];
string s;
int n,m;
int main()
{
	//by FLtops
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++m]=s[i]-'0';
		}
	}
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

