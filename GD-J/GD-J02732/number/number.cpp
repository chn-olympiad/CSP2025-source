#include<bits/stdc++.h>
using namespace  std;
long long b[110],n;
bool f=true;
char s='a';
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while((s>='0'&&s<='9')||(s>='a'&&s<='z'))
	{
		s=getchar();
		if(s>='0'&&s<='9')
		{
			int a=int(s-'0');
			b[a]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(i==0&&f)
		{
			cout<<"0";
			return 0;
		}
		for(int j=1;j<=b[i];j++)
		{
			cout<<i;
			f=false;
		}
	}
	return 0;
}
