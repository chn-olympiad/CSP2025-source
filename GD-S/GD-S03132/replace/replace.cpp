#include<bits/stdc++.h>
using namespace std;
int n,q,hx[5000005],hy[5000005];
char s1[5000005],s2[5000005],t1[5000005],t2[5000005];
long long f[5000005];
const long long w=33,p=19491001;
struct node
{
	int a,b,l;
}e[5000005];
long long ha1(register int l,register int r)
{
	return (hx[r]-hx[l-1]*f[r-l+1]%p+p)%p;
}
long long ha2(register int l,register int r)
{
	return (hy[r]-hy[l-1]*f[r-l+1]%p+p)%p;
}
int cmp(node u,node v)
{
	return u.l<v.l;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	register int i,j,k,l1,l2,ee,ans,s,t;
	long long q1,q2;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",s1+1,s2+1);
		l1=strlen(s1+1),l2=strlen(s2+1);
		q1=0,q2=0;
		for(j=1;j<=l1;j++)
			q1=(q1+(s1[j]-'a'+1+p)%p)%p*w%p;
		for(j=1;j<=l2;j++)
			q2=(q2+(s2[j]-'a'+1+p)%p)%p*w%p;
		e[i].a=q1,e[i].b=q2,e[i].l=l1;
	}
	sort(e+1,e+1+n,cmp);
	for(i=1;i<=q;i++)
	{
		scanf("%s%s",t1+1,t2+1);
		l1=strlen(t1+1),l2=strlen(t2+1),ans=0;
		if(l1!=l2)
		{
			printf("0\n");
			continue;
		}
		f[0]=1;
		for(j=1;j<=l1;j++)
			f[j]=f[j-1]*w%p;
		for(j=1;j<=l1;j++)
			hx[j]=(hx[j-1]+(t1[j]-'a'+1+p)%p)%p*w%p;
		for(j=1;j<=l2;j++)
			hy[j]=(hy[j-1]+(t2[j]-'a'+1+p)%p)%p*w%p;
		ee=0;
		for(j=l1;j>=1;j--)
			if(t1[j]!=t2[j])
			{
				ee=j;
				break;
			}
		for(j=1;j<=l1;j++)
		{
			if(t1[j-1]!=t2[j-1])
				break;
			for(k=1;k<=n;k++)
			{
				s=j,t=s+e[k].l-1;
				if(t>l1)
					break;
				if(t+1>ee&&ha1(s,t)==e[k].a&&ha2(s,t)==e[k].b)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
