#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1010,M=2010;
int n,m,p[2][N][M],slen[N];string str[2][N];bool vis[2][M];
void pre(int x)
{
	slen[x]=str[0][x].size()-1;
	p[0][x][1]=0;
	for(int i=1,j=0;i<slen[x];i++)
	{
		while(str[0][x][i+1]!=str[0][x][j+1]&&j>0) j=p[0][x][j];
		if(str[0][x][i+1]==str[0][x][j+1]) j++;
		p[0][x][i+1]=j;
	}
	p[1][x][1]=0;
	for(int i=1,j=0;i<slen[x];i++)
	{
		while(str[1][x][i+1]!=str[1][x][j+1]&&j>0) j=p[1][x][j];
		if(str[1][x][i+1]==str[1][x][j+1]) j++;
		p[1][x][i+1]=j;
	}
}
void KMP(int x,string a,string b)
{
	int len=a.size()-1;
	for(int i=0,j=0;i<len;i++)
	{
		while(a[i+1]!=str[0][x][j+1]&&j>0) j=p[0][x][j];
		if(a[i+1]==str[0][x][j+1]) j++;
		if(j==slen[x]) vis[0][i+1]=1,j=p[0][x][j];
	}
	for(int i=0,j=0;i<len;i++)
	{
		while(b[i+1]!=str[1][x][j+1]&&j>0) j=p[1][x][j];
		if(b[i+1]==str[1][x][j+1]) j++;
		if(j==slen[x]) vis[1][i+1]=1,j=p[1][x][j];
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>str[0][i]>>str[1][i];
		str[0][i]=" "+str[0][i];
		str[1][i]=" "+str[1][i];
		pre(i);
	}
	for(int i=1;i<=m;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		t1=" "+t1,t2=" "+t2;
		int len1=t1.size()-1,len2=t2.size()-1;
		if(len1!=len2) {printf("0\n");continue;}
		int l=1,r=len1;
		while(t1[l]==t2[l]&&l<=len1) l++;
		while(t1[r]==t2[r]&&r>0) r--;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			memset(vis,0,sizeof(vis));
			KMP(j,t1,t2);
			for(int k=r;k<=len1;k++)
			  if(vis[0][k]&&vis[1][k]&&r-slen[j]+1<=l) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
