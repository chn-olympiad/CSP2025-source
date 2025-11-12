#include<bits/stdc++.h>
using namespace std;
char s[200010][2010],t[200010][2010];
char u[2010],v[2010];
char tmp[2010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%s %s",s[i],t[i]);
	}
	while (q--)
	{
		int ret=0;
		scanf("%s %s",u,v);
		int lenu=strlen(u);
		int lenv=strlen(v);
		if (lenu!=lenv)
		{
			printf("0\n");
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			int lens=strlen(s[i]);
			for (int j=0;j<lenu-lens+1;j++)
			{
				strcpy(tmp,u);
				bool flag=true;
				for (int k=j;k<j+lens && flag;k++)
				{
					tmp[k]=t[i][k-j];
					if (u[k]!=s[i][k-j])flag=false;
				}
				if (flag)
				{
					if (strcmp(tmp,v)==0)ret++;
					break;
				}
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
