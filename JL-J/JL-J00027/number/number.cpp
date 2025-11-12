#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000050],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0' && s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--)
		printf("%lld",a[i]);
	return 0;
}
