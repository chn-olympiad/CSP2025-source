#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd()
{
	int s=0;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	  c=getchar();
	while(c>='0'&&c<='9')
	{
		s=(s<<3)+(s<<1)+c-'0';
		c=getchar();
	}
	  
	return s;
}
int n,m,k,f[30000],ys[30000],ans=99999999999999999,l,c[20][20000],ml,ss=0,lj,pd;
struct bs{
	int x,y,z;
}e[3000000],ye;
int cx(int x)
{
	while(x!=f[x])
	  x=f[x]=f[f[x]]=f[f[f[x]]];
	return x;
}
bool cmp(bs x,bs y)
{
	return x.z<y.z;
}
signed main()
{
	int x,y,xl,yl;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();m=rd();k=rd();
	for(int i=1;i<=m;i++)
	{
		e[i].x=rd();e[i].y=rd();e[i].z=rd();
	}
	sort(e+1,e+1+m,cmp);
	for(int i=0;i<k;i++)
	  for(int j=0;j<=n;j++)
	    c[i][j]=rd();
	l=(1<<k)-1;
	for(int i=0;i<=l;i++)
	{
	  ml=m;ss=0;lj=n;
	  for(int j=0;j<k;j++)
	    if(i&(1<<j))
	    {
	      ss+=c[j][0];lj++;
	      if(ss>=ans)
	        break;
	      for(int ij=1;ij<=n;ij++)
	      {
	      	e[++ml].x=lj;
	      	e[ml].y=ij;
	      	e[ml].z=c[j][ij];
		  }
		}
	  if(ss>=ans)
	    continue;
	  sort(e+m+1,e+1+ml,cmp);
	  for(int j=1;j<=lj;j++)
	    f[j]=j;
	  pd=0;x=1;y=m+1;
	  for(int j=1;j<=ml;j++)
	  {
	    if(x<=m&&y<=ml)
	  	  if(e[x].z<e[y].z)
	  	  {
	  		ye=e[x];
	  		x++;
		  }
	  	  else
	  	  {
	  		ye=e[y];
	  		y++;
		  }
		else
		{
		  if(x<=m)
	      {
	  	    ye=e[x];
	  	    x++;
	      }
	      if(y<=ml)
	      {
	  	    ye=e[y];
	  	    y++;
	      }	
		}	
	  	xl=cx(ye.x);
	  	yl=cx(ye.y);
	  	if(xl!=yl)
	  	{
	  	  pd++;
	  	  ss+=ye.z;
	  	  f[xl]=yl;
	  	  if(pd==lj-1||ss>=ans)
	  	  	break;
		}
	  }
	  if(ans>ss)
	    ans=ss;
	}
	printf("%lld",ans);
	return 0;
}

