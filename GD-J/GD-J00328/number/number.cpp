#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int len,x[20];
bool f;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1); 
	for(int i=1;i<=len;i++)if(s[i]>='0'&&s[i]<='9')x[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		if(x[i])
		{
			if(i==0&&!f)printf("0");
			else
			{
				f=1;
				for(int j=1;j<=x[i];j++)printf("%d",i);
			}
		}
	}
	return 0;
}
