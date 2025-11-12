#include<cstdio>
#include<iostream>
using namespace std;
struct LCT{
	struct node{
		int fa,ch[2],sum,w,rev,r/*,rsum*/;
	}t[110000];
	#define fa(x) t[(x)].fa
	#define ls(x) t[(x)].ch[0]
	#define rs(x) t[(x)].ch[1]
	#define rev(x) t[(x)].rev
	#define Max(x) t[(x)].sum
	#define upw(x) t[(x)].w
	#define fid(x) t[(x)].r
	int dir(int x){return rs(fa(x))==x;}
	bool Is_root(int x){return ls(fa(x))!=x&&rs(fa(x))!=x;}
	void push_up(int x)
	{
		Max(x)=0;
		if(Max(x)<Max(ls(x))) Max(x)=Max(ls(x)),fid(x)=0;
		if(Max(x)<Max(rs(x))) Max(x)=Max(rs(x)),fid(x)=1;
		if(Max(x)<upw(ls(x))) Max(x)=upw(ls(x)),fid(ls(x))=-1,fid(x)=0;
		if(Max(x)<upw(rs(x))) Max(x)=upw(rs(x)),fid(rs(x))=-1,fid(x)=1;
//		t[x].rsum=t[ls(x)].rsum+t[rs(x)].rsum+upw(ls(x))+upw(rs(x));
	}
	void change(int x){rev(x)^=1,swap(ls(x),rs(x));}
	void push_down(int x){if(rev(x)) change(ls(x)),change(rs(x)),rev(x)^=1;}
	void alldown(int x)
	{
		if(!Is_root(x)) alldown(fa(x));
		push_down(x);
	}
	void rotato(int x)
	{
		int y=fa(x),z=fa(y),r=dir(x);
		if(!Is_root(y)) t[z].ch[dir(y)]=x;
		fa(t[y].ch[r]=t[x].ch[!r])=y,fa(fa(t[x].ch[!r]=y)=x)=z;
		swap(upw(x),upw(y));
		push_up(y),push_up(x);
	}
	int splay(int x)
	{
		alldown(x);
		int fa=0;
		for(fa=fa(x);!Is_root(x);rotato(x),fa=fa(x))
			if(!Is_root(fa)) rotato(dir(x)==dir(fa)?fa:x);
		return x;
	}
	int access(int x)
	{
		int s=0;
		for(;x;s=x,x=fa(x))
			splay(x),rs(x)=s;
		return s;
	}
	void make_root(int x){access(x),splay(x),change(x);}
	void split(int x,int y){make_root(x),access(y);}
	void print(int n)
	{
		for(int i=1;i<=n;i++)
			printf("%d,%d,%d\n",t[i].fa,t[i].w,Is_root(i));
	}
	int find_root(int x)
	{
		access(x);
//		printf("-----------\n");
//		print(4);
//		printf("-----------\n");
		int s=x;
		while(ls(s)) s=ls(s);
		return s;
	}
	void link(int x,int y,int w)
	{
		make_root(x);
		if(find_root(y)!=x)
			rs(fa(y)=x)=y,t[y].w=w,push_up(y),push_up(x);
	}
	void cut(int x,int y)
	{
		make_root(x);
		if(find_root(y)==x&&t[y].ch[dir(x)]==x&&t[x].ch[!dir(x)]==0)
			t[y].ch[dir(x)]=0,fa(x)=0,upw(x)=0,push_up(y),push_up(x);
	}
	void glink(int x,int y,int w)
	{
		make_root(x);
		int tt=find_root(y);
		printf("$$  %d\n",tt);
		if(tt!=x)
		{
			rs(fa(y)=x)=y,t[y].w=w,push_up(y),push_up(x);
//			rs(fa(y)=x)=y;
			return ;
		}
		printf("he");
		split(x,y);
		if(Max(y)<=w) return ;
		int k=y;
		while(fid(k)!=-1) k=t[k].ch[fid(k)];
		cut(k,fa(k));
		link(x,y,w);
	}
	int get_ans(int n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=upw(i);
		}
		return sum;
	}
}g,gg;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g.glink(u,v,w);
//	printf("  hello\n");
//		g.print(n);
	}
	printf("%d\n",g.get_ans(n));
	g.split(1,4);
//	printf("hello");
	printf("%d\n",g.t[4].sum);
}
/*
5 6
1 2 1
1 5 2
2 3 6
2 4 5
5 3 4
5 4 3



4 4
1 2 1
1 3 1
2 4 1
3 4 2

*/
