#include<bits/stdc++.h>
using namespace std;
int a[1000005],k=0,l=0;
char s[1000005];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=strlen(s);
    for(int i=0;i<l;i++)
    {
		if(s[i]>='0'&&s[i]<='9') a[++k]=int(s[i]-'0');
	}
	sort(a+1,a+1+k,cmp);
	if(a[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cout<<a[i];
	}
    return 0;
}
