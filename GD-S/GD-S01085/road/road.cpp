#include<bits/stdc++.h>
using namespace std;
#define N 1100010
#define int long long
#define ls(x) x<<1
#define rs(x) x<<1|1 
int n,m,k,s;
struct node{
	int u,v,d,idx;
}a[N];
int w[20],L[20],R[20];
bool vis[N];
struct tree
{
	node b;
	int tag;
}t[N<<2];
inline node cmp(node x,node y)
{
	return x.d<y.d?x:y;
}
inline void push_up(int p)
{
	t[p].b=cmp(t[ls(p)].b,t[rs(p)].b);
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		t[p].b=a[l];
		t[p].b.idx=l;
		t[p].tag=0;
		t[ls(p)].b.d=t[rs(p)].b.d=1e16;
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
inline void push_down(int p,int l,int r)
{
	if(t[p].tag)
	{
		t[ls(p)].b.d=t[rs(p)].b.d+=t[p].tag;
		t[ls(p)].tag=t[rs(p)].tag=t[p].tag;
		t[p].tag=0;
	}
}
void erase(int p,int l,int r,int x)
{
	if(l==r)
	{
		t[p].b.d=1e16;
		return;
	}
	int mid=l+r>>1;
	push_down(p,l,r);
	if(x<=mid) erase(ls(p),l,mid,x);
	if(x>mid) erase(rs(p),mid+1,r,x);
	push_up(p);
}
void update(int p,int l,int r,int x,int y,int K)
{
	if(x<=l&&r<=y)
	{
		t[p].b.d+=K;
		t[p].tag=K;
		return;
	}
	int mid=l+r>>1;
	push_down(p,l,r);
	if(x<=mid) update(ls(p),l,mid,x,y,K);
	if(y>mid) update(rs(p),mid+1,r,x,y,K);
	push_up(p);
}
int f[20010];
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--)
	{
		int u,v,d;
		scanf("%lld%lld%lld",&u,&v,&d);
		a[++s]=(node){u,v,d,0};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&w[i]);
		L[i]=s+1;
		for(int j=1;j<=n;j++)
		{
			int t;
			scanf("%lld",&t);
			s++;
			a[s]=(node){n+i,j,t+w[i],0};
		}
		R[i]=s;
	}
	build(1,1,s);
	int oo=n;
	int ans=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	while(oo>1)
	{
		node q=t[1].b;
	//	cout<<q.d<<'\n';
		int x=find(q.u),y=find(q.v);
		if(x==y)
		{
			erase(1,1,s,q.idx);
			continue;
		}
		if(q.u>n||q.v>n){
			if(q.v>n) swap(q.u,q.v);
			ans+=q.d;
			f[y]=x;
			oo--;
			erase(1,1,s,q.idx);
			if(!vis[q.u-n])
			{
				oo++;
	//			cout<<L[q.u-n]<<' '<<R[q.u-n]<<'\n';
				update(1,1,s,L[q.u-n],R[q.u-n],-w[q.u-n]);
	//			cout<<1;
				vis[q.u-n]=1;
			}
		}else{
			f[y]=x;
			oo--;
			ans+=q.d;
			erase(1,1,s,q.idx);
		}
	//	cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
5 6 0
1 2 6
3 4 2
2 5 2
1 4 1
2 5 4
5 4 5
*/
