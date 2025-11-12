#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	string sss[10005],sss1[10005]; 
};
int n,m,lll,jl,jl1,ans;
string a[200005],b[200005];
map<string,map<string,node>> jljl;
string a1,b1,c1,d1,e1,g1;
int pd(string c1,string d1,int x,string e1,string g1)
{
	int ll=jljl[c1][d1].sss[x].size();
	string aaa="",bbb="";
	for(int j=0;j<ll;j++)
	{
		aaa+=jljl[c1][d1].sss[x][j];
	}
	for(int j=ll;j>=1;j--)
	{
		bbb+=e1[jl-j+1];
	}
	for(int j=0;j<ll;j++)
	{
		if(aaa[j]!=bbb[j])
		{
			return 0;
		}
	}
	aaa="",bbb="";
	int llll=jljl[c1][d1].sss1[x].size();
	for(int j=0;j<llll;j++)
	{
		if(jljl[c1][d1].sss1[x][j]!=g1[jl1+j]&&j!=0)
		{	
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a1="",b1="",c1="",d1="",e1="",g1="";
		cin>>a1>>b1;
		int lll=a1.size(),jl=-1,jl1=lll-1;
		for(int j=0;j<lll;j++)
		{
			if(a1[j]!=b1[j])
			{
				break;
			}
			jl=j;
		}
		for(int j=lll-1;j>=0;j--)
		{
			if(a1[j]!=b1[j])
			{
				break;
			}
			jl1-=1;
		}
		for(int j=jl+1;j<=jl1;j++)
		{
			c1+=a1[j],d1+=b1[j];
		}
		for(int j=0;j<=jl;j++)
		{
			e1+=a1[j];
		}
		for(int j=jl1+1;j<lll;j++)
		{
			g1+=a1[j];
		}
		jljl[c1][d1].a+=1,jljl[c1][d1].sss[jljl[c1][d1].a]=e1,jljl[c1][d1].sss1[jljl[c1][d1].a]=g1;
	}
	for(int i=1;i<=m;i++)
	{
		ans=0;
		a1="",b1="",c1="",d1="",e1="",g1="";
		cin>>a1>>b1;
		lll=a1.size(),jl=-1,jl1=lll-1;
		for(int j=0;j<lll;j++)
		{
			if(a1[j]!=b1[j])
			{
				break;
			}
			jl+=1;
		}
		for(int j=lll-1;j>=0;j--)
		{
			if(a1[j]!=b1[j])
			{
				break;
			}
			jl1-=1;
		}
		for(int j=jl+1;j<=jl1;j++)
		{
			c1+=a1[j],d1+=b1[j];
		}
		for(int j=0;j<=jl;j++)
		{
			e1+=a1[j];
		}
		for(int j=jl1+1;j<lll;j++)
		{
			g1+=a1[j];
		}
		for(int j=1;j<=jljl[c1][d1].a;j++)
		{
			if(pd(c1,d1,j,e1,g1)==1)
			{
				ans+=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
