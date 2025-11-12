#include<bits/stdc++.h>
using namespace std;
char c[1000010];
int t,l;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	l=strlen(c);
	sort(c,c+l,cmp);
	for(int i=0;i<l;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			t=i;
			break;
		}
	}
	for(int i=t;i<l;i++)
	{
		printf("%c",c[i]);
	}
	return 0;
}
