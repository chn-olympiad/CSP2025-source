#include<bits/stdc++.h>
using namespace std;
string s;
int l,cnt,l1,r1=-1;
int a[1000005],
b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
