#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		n[++cnt]=s[i]-'0';
	}
	sort(n+1,n+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<n[i];
	}
	return 0;
}
