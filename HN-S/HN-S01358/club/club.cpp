#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;
const int N=1e5+10;
int T,n,k;
int d[4];
struct Node{
	int a,b,c;
};
Node w[N],b[N];
int cnt;

int get_max(Node x)
{
	if(x.a>=x.b&&x.a>=x.c) return 1;
	if(x.b>=x.a&&x.b>=x.c) return 2;
	if(x.c>=x.a&&x.c>=x.b) return 3;
}

int gd(Node x,int d)
{
	if(d==1) return max(x.b,x.c);
	if(d==2) return max(x.a,x.c);
	if(d==3) return max(x.a,x.b);
}

int gm(Node x)
{
	return max(x.a,max(x.b,x.c));
}

bool cmp(Node x,Node y)
{
	return gm(x)-gd(x,k)>gm(y)-gd(y,k);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		d[1]=d[2]=d[3]=0;
		cnt=0;
		k=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			w[i]={a,b,c};
			d[get_max(w[i])]++;
		}
		LL ans=0;
		if(d[1]<=n/2&&d[2]<=n/2&&d[3]<=n/2)
		{
			for(int i=1;i<=n;i++)
				ans+=gm(w[i]);
		}
		else
		{
			if(d[1]>n/2) k=1;
			else if(d[2]>n/2) k=2;
			else k=3;
			for(int i=1;i<=n;i++)
			{
				if(get_max(w[i])==k) continue;
				ans=ans+gm(w[i]);
			}
			for(int i=1;i<=n;i++)
			{
				if(get_max(w[i])==k)
					b[++cnt]=w[i];
			}
			sort(b+1,b+cnt+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=gm(b[i]);
			for(int i=n/2+1;i<=cnt;i++) ans+=gd(b[i],k);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
