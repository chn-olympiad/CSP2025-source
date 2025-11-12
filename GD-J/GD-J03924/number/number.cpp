#include<bits/stdc++.h>
using namespace std;
string ch;
int l,cnt,a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ch;
	l=ch.size();
	for(int i=0;i<l;i++)
	{
		if(ch[i]>='0' and ch[i]<='9')
		{
			cnt++;
			a[cnt]=(int)(ch[i]-'0');
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d",a[i]);
	}
}
