#include<bits/stdc++.h>
using namespace std;
int n,q;
char ch1[1005][200005];
char ch2[1005][200005];
int len1[1005];
int len2[1005];
int x[1005];
int xb[1005];
int ans=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>ch1[i];len1[i]=strlen(ch1[i]); 
		cin>>ch2[i];len2[i]=strlen(ch2[i]);
		int t1,t2;
		for(int j=0;j<=len1[i]-1;j++)
		{
			if(ch1[i][j]=='b')t1=j;
			xb[i]=j;
		}
		for(int j=0;j<=len2[i]-1;j++)
		{
			if(ch2[i][j]=='b')t2=j;
		}
		x[i]=t1-t2;
	}
	for(int i=1;i<=q;i++)
	{
		char k1[2005],k2[2005];
		cin>>k1;
		int lena=strlen(k1); 
		cin>>k2;
		int lenb=strlen(k2);
		int t1,t2;
		for(int j=0;j<lena;j++)
		{
			if(k1[j]=='b')t1=j;
		}
		for(int j=0;j<lenb;j++)
		{
			if(k2[j]=='b')t2=j;
		}
		int x2=t1-t2;
		for(int i=1;i<=n;i++)
		{
			if(x[i]==x2&&xb[i]<=t1&&len1[i]-xb[i]-1<=lena-t1-1)ans++;
		}
	}
	printf("%d\n",ans);
}
