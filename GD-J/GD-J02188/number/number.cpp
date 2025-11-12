#include<bits/stdc++.h>
using namespace std;
char a[1005000];
int ans[15],len;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9') 
		ans[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=ans[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
