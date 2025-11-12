#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char s[N];
	int sum[10];
	
	memset(sum,0,sizeof(sum));
	
	scanf("%s",&s+1);
	for(int i=1;;i++)
	{
		if(s[i]<='9'&&s[i]>='0')sum[s[i]-'0'+1]++;
		if(s[i]==' ')break;
	}
		
	int ans[N],t=0;
	for(int i=9;i>=0;i--)
	{
		while(sum[i]--)
		{
			ans[++t]=i;
			
		}
	}
	for(int i=1;i<=t;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
