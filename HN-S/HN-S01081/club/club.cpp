# include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z,d;
}N[100005];
int a[100005],b[100005],c[100005];
bool cmp(int n1,int n2)
{
	return N[n1].d<N[n2].d;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n,n1=0,n2=0,n3=0,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			N[i]=(Node){x,y,z,max(max(x,y),z)*2+min(min(x,y),z)-x-y-z};
			if(x>=y and x>=z) a[++n1]=i,ans+=x;
			else if(y>=x and y>=z) b[++n2]=i,ans+=y;
			else if(z>=x and z>=y) c[++n3]=i,ans+=z;
		}
		if(n1>n/2)
		{
			sort(a+1,a+1+n1,cmp);
			for(int i=1;i<=n1-n/2;i++) ans-=N[a[i]].d;
		}
		if(n2>n/2)
		{
			sort(b+1,b+1+n2,cmp);
			for(int i=1;i<=n2-n/2;i++) ans-=N[b[i]].d;
		}
		if(n3>n/2)
		{
			sort(c+1,c+1+n3,cmp);
			for(int i=1;i<=n3-n/2;i++) ans-=N[c[i]].d;
		}
		printf("%d\n",ans);
	}
	return 0;
}

