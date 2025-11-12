#include<bits/stdc++.h>
using namespace std;

char s[1000010];
char ans[1000010];
int cnt=0;

bool cmp(const char &x,const char &y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[cnt]=s[i];
			cnt++;
		}
	}
	sort(ans,ans+cnt,cmp);
	printf("%s",ans);
	return 0;
}
