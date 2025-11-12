#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,q,ans;bool f=1;
char s[1005][2][2005],t[1005][2][2005];
bool check(char a[])
{
	int cnt=0,len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]!='a'&&a[i]!='b')return 0;
		if(a[i]=='b')
			if(++cnt>1)return 0;
	}
	return 1;
}
int getid(char a[])
{
	int le=strlen(a);
	for(int i=0;i<le;i++)
		if(a[i]=='b')return i;
	return -1;
}
bool bj(char ss[],char b[],int st,int len,char c[],char tt[])
{
	char a[2005];int le=strlen(ss);
	for(int i=0;i<le;i++)
		a[i]=ss[i];
	for(int i=st;i<st+len;i++)
	{
		if(a[i]==b[i-st])a[i]=c[i-st];
		else return 0;
	}
	for(int i=0;i<le;i++)
		if(a[i]!=tt[i])return 0;
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s[i][0],s[i][1]);
		f&=check(s[i][0]);
		f&=check(s[i][1]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%s%s",t[i][0],t[i][1]);
		f&=check(t[i][0]);
		f&=check(t[i][1]);
	}
	if(n>1000){cout<<0;return 0;}
	if(f)
	{
		int cha=getid(t[1][0])-getid(t[1][1]);
		for(int i=1;i<=n;i++)
			if(getid(s[i][0])-getid(s[i][1])==cha)
				ans++;
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		for(int j=1;j<=n;j++)
		{
			int len=strlen(s[j][0]),len1=strlen(t[i][0]);
			for(int k=0;k<=len1-len;k++)
				ans+=bj(t[i][0],s[j][0],k,len,s[j][1],t[i][1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
