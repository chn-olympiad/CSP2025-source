#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num,i,a,b,c,ab,bc,ac;
}num[100010],ab[100010],bc[100010],ac[100010];
bool bum[100010];
bool cmp_ab(node a,node b)
{
	if(a.ab==b.ab)return a.a>a.b;
	return a.ab>b.ab;
}
bool cmp_bc(node a,node b)
{
	if(a.bc==b.bc)return a.b>a.c;
	return a.bc>b.bc;
}
bool cmp_ac(node a,node b)
{
	if(a.ac==b.ac)return a.a>a.c;
	return a.ac>b.ac;
}
int cmax(int a,int b,int c)
{
	if(a>=b && a>=c)return 1;
	if(b>=a && b>=c)return 2;
	if(a>=a && c>=b)return 3;
	return -1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(bum,0,sizeof(bum));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&num[i].a,&num[i].b,&num[i].c);
			num[i].ab=abs(num[i].a-num[i].b);
			num[i].bc=abs(num[i].b-num[i].c);
			num[i].ac=abs(num[i].a-num[i].c);
			num[i].i=i;
			ab[i]=bc[i]=ac[i]=num[i];
		}
		sort(ab+1,ab+n+1,cmp_ab);
		sort(bc+1,bc+n+1,cmp_bc);
		sort(ac+1,ac+n+1,cmp_ac);
		ab[n+1].ab=-1,ab[n+1].a=0,ab[n+1].b=0;
		bc[n+1].bc=-1,bc[n+1].b=0,bc[n+1].c=0;
		ac[n+1].ac=-1,ac[n+1].a=0,ac[n+1].c=0;
		long long t1=1,t2=1,t3=1,s1=0,s2=0,s3=0,sum=0;
		while(t1<=n || t2<=n || t3<=n)
		{
			while(bum[ab[t1].i] && t1<=n)t1+=1;
			while(bum[bc[t2].i] && t2<=n)t2+=1;
			while(bum[ac[t3].i] && t3<=n)t3+=1;
			bool flag=0;
			if(s1>=n/2)flag=1,ab[t1].a=ac[t3].a=0,ab[t1].ab=abs(ab[t1].a-ab[t1].b),ac[t3].ac=abs(ac[t3].a-ac[t3].c);
			if(s2>=n/2)flag=1,ab[t1].b=bc[t2].b=0,ab[t1].ab=abs(ab[t1].a-ab[t1].b),bc[t2].bc=abs(bc[t2].b-bc[t2].c);
			if(s3>=n/2)flag=1,bc[t2].c=ac[t3].c=0,bc[t2].bc=abs(bc[t2].b-bc[t2].c),ac[t3].ac=abs(ac[t3].a-ac[t3].c);
			if(cmax(ab[t1].ab,bc[t2].bc,ac[t3].ac)==1)//ab
			{
				sum+=max(ab[t1].a,ab[t1].b);
				bum[ab[t1].i]=1;
				t1++;
				if(max(ab[t1].a,ab[t1].b)==ab[t1].a)s1++;
				else if(max(ab[t1].a,ab[t1].b)==ab[t1].b)s2++;
			}else if(cmax(ab[t1].ab,bc[t2].bc,ac[t3].ac)==2)//bc
			{
				sum+=max(bc[t2].b,bc[t2].c);
				bum[bc[t2].i]=1;
				t2++;
				if(max(bc[t2].b,bc[t2].c)==bc[t2].b)s2++;
				else if(max(bc[t2].b,bc[t2].c)==bc[t2].c)s3++;
			}else if(cmax(ab[t1].ab,bc[t2].bc,ac[t3].ac)==3)//ac
			{
				sum+=max(ac[t3].a,ac[t3].c);
				bum[ac[t3].i]=1;
				t3++;
				if(max(ac[t3].a,ac[t3].c)==ac[t3].a)s1++;
				else if(max(ac[t3].a,ac[t3].c)==ac[t3].c)s3++;
			}
		}
		printf("%lld\n",sum);
	}
}
