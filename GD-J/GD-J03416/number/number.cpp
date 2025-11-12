#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;

ll n,tot=0,ans=0;
ll a[N];
char s[N];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	n=strlen(s)-1;
	for(int i=0;i<=n;i++)
	{
		if(s[i]<='9' && s[i]>='0')
		{
			a[++tot]=s[i]-'0';
		} 
	} 
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
