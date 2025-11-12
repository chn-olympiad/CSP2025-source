#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
using namespace std;

bool k1;

#define dif asdifouaisodf
const int N=200005,M=5e6+5;
int n,Q;
vector<char>c1[N],c2[N];
int dif[N][2];
ull oth[N][2];
char s[M],s2[M],s3[M];
int bzcnt;
ull lum[M],rum[M],jz[M];
unordered_map<ull,int>bz;
vector<int>bzh[N];

bool k2;

ull geths(char *x,char *y,int &p1,int &p2)
{
	int len=strlen(x+1);
	p1=1,p2=0;
	for(int i=1;i<=len;i++)
	{
		if(x[i]!=y[i]) 
		{
			p1=i;
			break;
		}
	}
	for(int i=len;i;i--)
		if(x[i]!=y[i])
		{
			p2=i;
			break;
		}
	ull now=0,now2=0;
	for(int i=p1;i<=p2;i++)
	{
		now=now*131+x[i];
		now2=now*131+y[i];
	}
	return now*now2;
}

int main()
{
//	cout<<abs(&k1-&k2)/1024/1024;return 0;
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	jz[0]=1;
	for(int i=1;i<M;i++) jz[i]=jz[i-1]*131;
	
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		c1[i].pb('0');
		for(int j=1;s[j];j++)
			c1[i].pb(s[j]);
			
		scanf("%s",s2+1);
		c2[i].pb('0');
		for(int j=1;s2[j];j++)
			c2[i].pb(s2[j]);
		
		int p1,p2;
		ull x=geths(s,s2,p1,p2);
		if(!x) continue;
		if(!bz[x]) bz[x]=++bzcnt;
		bzh[bz[x]].pb(i);
		
		for(int j=1;j<p1;j++)
			oth[i][0]=oth[i][0]*131+s[j];
		int len=strlen(s+1);
		for(int j=p2+1;j<=len;j++)
			oth[i][1]=oth[i][1]*131+s[j];
		dif[i][0]=p1-1,dif[i][1]=len-p2;
		
		
//		for(int j=1;j<p1;j++)
//		if(s[j]!=s2[j])
//		{
//			puts("***");
//			return 0;
//		}
//		for(int j=len;j>p2;j--)
//		if(s[j]!=s2[j])
//		{
//			puts("***");
//			return 0;
//		}
		
	}
	
	int Q2=Q;
	while(Q--)
	{
		scanf("%s",s+1);
		scanf("%s",s2+1);
		int len=strlen(s+1);
		
		if(n<=100 && Q2<=100 && len<=200)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j+(int)c1[i].size()-2<=len;j++)
				{
					int flag=1;
					for(int k=j;k<=j+(int)c1[i].size()-2;k++)
						if(s[k]!=c1[i][k-j+1]) 
						{
//							if(i==3 && j==3) printf("**%d\n",k);
							flag=0;
							break;
						}
					if(flag)
					{
//						puts("**");
						for(int j=1;j<=len;j++) s3[j]=s[j];
						for(int k=j;k<=j+(int)c1[i].size()-2;k++)
							s3[k]=c2[i][k-j+1];
						int flag2=1;
						for(int k=1;k<=len;k++)
							if(s3[k]!=s2[k])
							{
								flag2=0;
								break;
							}
						ans+=flag2;
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		
		int p1,p2;
		ull now=geths(s,s2,p1,p2);
		
//		if(now==0) 
//		{
//			puts("***");return 0;
//		}
		
		lum[p1]=rum[p2]=0;
		for(int i=p1-1;i;i--)
			lum[i]=lum[i+1]+s[i]*jz[p1-i-1];
		for(int i=p2+1;i<=len;i++)
			rum[i]=rum[i-1]*131+s[i];
		
		int ans=0;
		int k=bz[now];
		for(int i:bzh[k])
		{
			if(p1-dif[i][0]>=1 && p2+dif[i][1]<=len && 
				oth[i][0]==lum[p1-dif[i][0]] && oth[i][1]==rum[p2+dif[i][1]])
				ans++;
		}
		
		printf("%d\n",ans);
	}
	return 0;
}

