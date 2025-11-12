#include<bits/stdc++.h>
using namespace std;
int n,q;
struct S{
	int n,b1,cha;
}p[200005];
char s[5000005];
char t[5000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",(s+1));
		p[i].n=strlen(s+1);
		for(int j=1;j<=p[i].n;j++)
		{
			if(s[j]=='b')
			{
				p[i].b1=j;
				break;
			}
		}
		scanf("%s",(s+1));
		for(int j=1;j<=p[i].n;j++)
		{
			if(s[j]=='b')
			{
				p[i].cha=j-p[i].b1;
				break;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int cnt=0;
		scanf("%s",(s+1));
		scanf("%s",(t+1));
		int nst=strlen(s+1);
		int nts=strlen(t+1);
		if(nst!=nts)
		{
			printf("0\n");
			continue;
		}
		int bs=0,bt=0;
		for(int j=1;j<=nst;j++)
		{
			if(s[j]=='b')
				bs=j;
			if(t[j]=='b')
				bt=j;
			if(bs!=0 && bt!=0)
				break;
		}
		//cout<<bs<<bt<<endl;
		int cst=bt-bs;
		for(int j=1;j<=n;j++)
		{
			if((p[j].b1<=bs && p[j].n-p[j].b1<=nst-bs) && p[j].cha==cst)
			{
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
