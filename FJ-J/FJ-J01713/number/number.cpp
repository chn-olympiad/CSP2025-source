#include<bits/stdc++.h>
using namespace std;
char c[1000777];
int ans[1000777];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	scanf("%s",c);
	for(int i=0;i<strlen(c);i++)
	{
		if(isdigit(c[i]))
		{
			ans[k]=c[i]-'0';
			k++;
		}
	}
	sort(ans,ans+k,cmp);
	for(int i=0;i<k;i++)
	{
		printf("%d",ans[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

