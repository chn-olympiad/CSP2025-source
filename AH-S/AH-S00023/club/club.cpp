#include<bits/stdc++.h>
using namespace std;
long long t,n,m[100010],o[100010],p[100010],tot;
struct node{
	long long a,b,c;
}s[100010];
int cmp(node x,node y)
{
	return x.a>x.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			m[i]+=m[i-1]+s[i].a;
			o[i]+=o[i-1]+s[i].b;
			p[i]+=p[i-1]+s[i].c;
		}
		if(n==2) tot=max(tot,max(s[1].a+s[2].b,max(s[1].a+s[2].c,max(s[1].b+s[2].a,max(s[1].b+s[2].c,max(s[1].c+s[2].a,s[1].c+s[2].b))))));
		else if(o[n]==0&&p[n]==0)
		{
			sort(s+1,s+n+1,cmp);
			for(int i=n;i>n/2;i--) tot+=s[i].a;
		}
		cout<<tot<<'\n';
	}
	return 0;
}
