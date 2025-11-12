#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
struct Date{
	int st,ed;
};Date a[N*2],b[N*2];
int n,m,c[M],d[M],ans[N],ss,l[N*2],r[N*2],L[N*2],R[N*2],id[N*2],q[N],tr[M],ti,tag[M],MA;
char ch[M];
unsigned long long f[M],F[M],g[N*2];
void solveBF()
{
	int i,j,k,len;
	F[0]=1;
	for(i=1;i<=5e6;i++)
	F[i]=F[i-1]*27;
	for(i=1;i<=n*2;i++)
	{
		for(j=0;j<=a[i].ed-a[i].st;j++)
		g[i]+=F[j]*c[a[i].st+j];
	}
	for(i=2;i<=m*2;i+=2)
	{
		if(b[i].ed-b[i].st!=b[i-1].ed-b[i-1].st)
		continue;
		for(j=b[i-1].st;j<=b[i].ed;j++)
		f[j]=f[j-1]+F[j]*d[j];
		for(j=r[i-1];j<=b[i].ed-b[i].st;j++)
		{
			for(k=2;k<=n*2;k+=2)
			{
				len=a[k].ed-a[k].st;
				if(j-len<=l[i-1]&&j>=len)
				{
					if(g[k]*F[j+b[i].st-len]==f[j+b[i].st]-f[j+b[i].st-len-1]&&g[k-1]*F[j+b[i-1].st-len]==f[j+b[i-1].st]-f[j+b[i-1].st-len-1])
					ans[i/2]++;
				}
			}
		}
	}
}
bool cmpa(int x,int y)
{
	if(R[x]-L[x]<R[y]-L[y]||(R[x]-L[x]==R[y]-L[y]&&L[x]<L[y]))
	return 1;
	return 0;
}
bool cmpq(int x,int y)
{
	if(r[x]-l[x]<r[y]-l[y]||(r[x]-l[x]==r[y]-l[y]&&l[x]<l[y]))
	return 1;
	return 0;
}
void xg(int x)
{
	while(x<=MA)
	{
		if(tag[x]!=ti)
		{
			tag[x]=ti;tr[x]=0;
		}
		tr[x]++;x+=x&-x;
	}
}
int cz(int x)
{
	int s=0;
	while(x>0)
	{
		if(tag[x]!=ti)
		{
			tag[x]=ti;tr[x]=0;
		}
		s+=tr[x];x-=x&-x;
	}
	return s;
}
void solvespB()
{
	int i,j,x,y;
	for(i=1;i<=n*2;i+=2)
	{
		for(j=0;j<=a[i].ed-a[i].st;j++)
		{
			if(c[j+a[i].st]!=1)
			{
				L[(i+1)/2]=j;break;
			}
		}
		for(j=a[i].ed-a[i].st;j>=0;j--)
		{
			if(c[j+a[i+1].st]!=1)
			{
				R[(i+1)/2]=j;break;
			}
		}
	}
	for(i=1;i<=n;i++)
	id[i]=i,MA=max(MA,a[i*2-1].ed-a[i*2-1].st+1);
	for(i=1;i<=m*2;i+=2)
	{
		for(j=0;j<=b[i].ed-b[i].st;j++)
		{
			if(d[j+b[i].st]!=1)
			{
				l[(i+1)/2]=j;break;
			}
		}
		for(j=b[i+1].ed-b[i+1].st;j>=0;j--)
		{
			if(d[j+b[i+1].st]!=1)
			{
				r[(i+1)/2]=j;break;
			}
		}
	}
	for(i=1;i<=m;i++)
	q[i]=i,MA=max(MA,b[i*2-1].ed-b[i*2-1].st+1);
	sort(id+1,id+n+1,cmpa);sort(q+1,q+m+1,cmpq);
	MA++;
	for(i=1,j=1;i<=m;i++)
	{
		x=q[i];
		if(r[x]-l[x]!=r[q[i-1]]-l[q[i-1]])
		ti++;
		while(j<=n&&r[x]-l[x]>R[id[j]]-L[id[j]])
		j++;
		while(j<=n&&r[x]-l[x]==R[id[j]]-L[id[j]]&&L[id[j]]<=l[x])
		{
			y=id[j];
			xg((a[y*2-1].ed-a[y*2-1].st)-R[y]+1);j++;
		}
		if(b[x*2-1].ed-b[x*2-1].st==b[x*2].ed-b[x*2].st)
		ans[x]=cz((b[x*2-1].ed-b[x*2-1].st)-r[x]+1);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int len,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch);
		a[i*2-1].st=ss+1;len=strlen(ch);
		for(j=0;j<len;j++)
		c[++ss]=ch[j]-'a'+1;
		a[i*2-1].ed=ss;
		scanf("%s",ch);
		a[i*2].st=ss+1;len=strlen(ch);
		for(j=0;j<len;j++)
		c[++ss]=ch[j]-'a'+1;
		a[i*2].ed=ss;
	}
	ss=0;
	for(i=1;i<=m;i++)
	{
		scanf("%s",ch);
		b[i*2-1].st=ss+1;len=strlen(ch);
		for(j=0;j<len;j++)
		d[++ss]=ch[j]-'a'+1;
		b[i*2-1].ed=ss;
		scanf("%s",ch);
		b[i*2].st=ss+1;len=strlen(ch);
		for(j=0;j<len;j++)
		d[++ss]=ch[j]-'a'+1;
		b[i*2].ed=ss;
	}
	for(i=1;i<=m*2;i+=2)
	{
		if(b[i].ed-b[i].st!=b[i+1].ed-b[i+1].st)
		continue;
		for(j=0;j<=b[i].ed-b[i].st;j++)
		{
			if(d[b[i].st+j]!=d[b[i+1].st+j])
			{
				l[i]=j;break;
			}
		}
		for(j=b[i].ed-b[i].st;j>=0;j--)
		{
			if(d[b[i].st+j]!=d[b[i+1].st+j])
			{
				r[i]=j;break;
			}
		}
	}
	if(n<=1000&&ss<=2000)
	solveBF();
	else
	solvespB();
	for(i=1;i<=m;i++)
	printf("%d\n",ans[i]);
	return 0;
}
