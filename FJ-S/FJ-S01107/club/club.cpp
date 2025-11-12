#include<bits/stdc++.h>
using namespace std;
int n,t,b1[100050],b2[100050],b3[100050],b1n=0,b2n=0,b3n=0;
long long ans=0;
struct node{
	int b[4];
}a[100050];
int max(int x,int y)
{
	if(x>y)
		return x;
	return y;
}
bool cmp1(int x,int y)
{
	return a[x].b[1]-max(a[x].b[2],a[x].b[3])>a[y].b[1]-max(a[y].b[2],a[y].b[3]);
}
bool cmp2(int x,int y)
{
	return a[x].b[2]-max(a[x].b[1],a[x].b[3])>a[y].b[2]-max(a[y].b[1],a[y].b[3]);
}
bool cmp3(int x,int y)
{
	return a[x].b[3]-max(a[x].b[2],a[x].b[1])>a[y].b[3]-max(a[y].b[2],a[y].b[1]);
}
void p1()
{
	while(b1n>n/2)
	{
		ans-=a[b1[b1n]].b[1]-max(a[b1[b1n]].b[2],a[b1[b1n]].b[3]);
		b1n--;
	}
}
void p2()
{
	while(b2n>n/2)
	{
		ans-=a[b2[b2n]].b[2]-max(a[b2[b2n]].b[1],a[b2[b2n]].b[3]);
		b2n--;
	}
}
void p3()
{
	while(b3n>n/2)
	{
		ans-=a[b3[b3n]].b[3]-max(a[b3[b3n]].b[2],a[b3[b3n]].b[1]);
		b3n--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
 	while(t--)
	{
		scanf("%d",&n);
		ans=b1n=b2n=b3n=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].b[1],&a[i].b[2],&a[i].b[3]);
		for(int i=1;i<=n;i++)
		{
			if(a[i].b[1]>=max(a[i].b[2],a[i].b[3]))
				b1[++b1n]=i;
			else
				if(a[i].b[2]>=max(a[i].b[1],a[i].b[3]))
					b2[++b2n]=i;
				else
					b3[++b3n]=i;
			ans+=max(max(a[i].b[1],a[i].b[2]),a[i].b[3]);
		}
		sort(b1+1,b1+b1n+1,cmp1);
		sort(b2+1,b2+b2n+1,cmp2);
		sort(b3+1,b3+b3n+1,cmp3);
		if(b1n>n/2)
			p1();
		if(b2n>n/2)
			p2();
		if(b3n>n/2)
			p3();
		printf("%lld\n",ans);
	}
	return 0;
}

