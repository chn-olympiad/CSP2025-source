#include<bits/stdc++.h>
using namespace std;
int n,q,len;
int a[5000010][27],cnt,lt[5000010];
string s1,s2[200010],s0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2[i];
		int len=s1.length(),now=0;
		for(int j=0;j<len;j++)
		{
			int k=s1[j]-'a';
			if(!a[now][k]) a[now][k]=++cnt;
			now=a[now][k];
		}
		lt[now]=i;
	}
	while(q--)
	{
		int ans=0;
		cin>>s0>>s1;
		int len=s0.length(),len1=s1.length();
		if(len1!=len)
		{
			printf("0\n");
			continue;
		}
		int l,r;
		for(int i=0;i<len;i++)
		{
			if(s0[i]!=s1[i])
			{
				l=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--)
		{
			if(s0[i]!=s1[i])
			{
				r=i;
				break;
			}
		}
		for(int i=0;i<=l;i++)
		{
			int now=0;
			for(int j=i;j<len;j++)
			{
				int k=s0[j]-'a';
				if(a[now][k])
				{
					now=a[now][k];
					if(lt[now]&&j>=r)
					{
						int o=lt[now];
						bool flag=1; 
						for(int k=i;k<=j;k++)
						{
							if(s1[k]!=s2[o][k-i])
							{
								flag=0;
								break;
							}
						}
						if(flag) ans++;
					}
				 } 
				else break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
 } 

