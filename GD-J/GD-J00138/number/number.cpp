#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int f[1000005],cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			f[++cnt]=a[i]-'0';
		}
	}
	sort(f+1,f+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<f[i];
	}
	return 0;
}
