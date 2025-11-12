#include<bits/stdc++.h>
// #define int long long
#define filein(x) freopen(x".in","r",stdin)
#define fileout(x) freopen(x".out","w",stdout)
using namespace std;
namespace glm
{
	const int N=1e5+9;
	#define lowbit(x) (x&(-x))
	struct bit
	{
		int c[N];
		void add(int x,int k)
		{
			for(;x<N;x+=lowbit(x))
			c[x]+=k;
		}
		int ask(int x)
		{
			int now=0;
			for(;x;x-=lowbit(x))
			now+=c[x];
			return now;
		}
		int ask(int l,int r)
		{
			return ask(r)-ask(l-1);
		}
	};
	#undef lowbit
	struct sgt
	{
		int d[N<<2],lz[N<<2];
		void pushup(int p)
		{
		}
		void upd(int p,int k)
		{
		}
		void pushdown(int p)
		{
			upd(p<<1,lz[p]);
			upd(p<<1|1,lz[p]);
			lz[p]=0;
		}
		void update(int p,int l,int r,int L,int R,int k)
		{
			if(L<=l&&r<=R)
			return upd(p,k);
			int mid=(l+r)/2;
			pushdown(p);
			if(L<=mid)
			update(p<<1,l,mid,L,R,k);
			if(R>mid)
			update(p<<1|1,mid+1,r,L,R,k);
			pushup(p);
		}
	};
	struct Treap
	{
		struct Node
		{
			int val,pri,siz;
			int ls,rs;
		}d[N];
		int root;
		void pushup(int p)
		{
			d[p].siz=d[d[p].ls].siz+d[d[p].rs].siz+1;
		}
		int merge(int x,int y)
		{
			if(!x||!y)
			return x+y;
			if(d[x].pri<d[y].pri)
			{
				d[x].rs=merge(d[x].rs,y);
				pushup(x);
				return x;
			}
			else
			{
				d[y].ls=merge(x,d[y].ls);
				pushup(y);
				return y;
			}
		}
		// pair<int,int> split(int p,int k)
		// {
		// 	if(!x)
		// 	return 0;
		// 	if(d[p].val<=k)
		// 	{
		// 		auto tmp=split(d[p].rs,k);
		// 		d[p].rs=tmp.first;
		// 		pushup(p);
		// 		return {p,tmp.second};
		// 	}
		// }
	};
}
signed main()
{
	return 0;
}
/*
(;-;)
*/