#include<bits/stdc++.h>
#define ll long long


using namespace std;

const int N=1e6+1000;
char ch[N];
int a[N],la=0;

int main()
{
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	
	scanf("%s",ch+1);
	
	int l=strlen(ch+1);
	for(int i=1;i<=l;++i)
	{
		if(ch[i]>='0'&&ch[i]<='9')
		{
			a[++la]=ch[i]-'0';
		}
	}
	
	sort(a+1,a+la+1);
	
	for(int i=la;i>=1;--i)
	{
		printf("%d",a[i]);
	}
	
	return 0;
}
