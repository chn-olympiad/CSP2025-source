#include<bits/stdc++.h>
using namespace std;
char s[1000010];
long long a[10]={0};
int num=0;
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	int lens=strlen(s);
	for(int i=0;i<lens;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num=s[i]-'0';
			a[num]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
