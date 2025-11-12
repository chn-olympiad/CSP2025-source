#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],cnt;
char in;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	in=getchar();
	while(('0'<=in&&'9'>=in)||('a'<=in&&in<='z'))
	{
		if('0'<=in&&in<='9')	a[++cnt]=in-'0';
		in=getchar();
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0)
	{
		cout<<"0\n";
		return 0;
	}
	for(int i=cnt;i>0;i--)	cout<<a[i];
	cout<<"\n";
	return 0;
}