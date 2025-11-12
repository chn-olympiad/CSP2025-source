#include<bits/stdc++.h>
using namespace std;
int n,x,a[1000006],t;
char s[1000006];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t++;
			x=s[i]-'0';
			a[t]=x;
		}
	}
	sort(a+1,a+1+t);
	for(int i=t;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
