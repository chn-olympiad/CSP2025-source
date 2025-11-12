#include<bits/stdc++.h>
using namespace std;
char s[10000010];
int a[10000010],q=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			int x=int(s[i]-'0');
			a[q]=x;
			q++;
		}
	}
	sort(a,a+q+1);
	for(int i=q;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}

