#include<bits/stdc++.h>
using namespace std;
char s[1000002];
long long n;
long long a[1000002];
long long cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[++cnt]=s[i]-48;
		}
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0)
	{
		cout<<"0";
	}else{
		for(int i=cnt;i>=1;i--)
		{
			cout<<a[i];
		}
	}
}
