#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]>='0' && s[i-1]<='9')
		{
			cnt++;
			a[cnt]=s[i-1]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
