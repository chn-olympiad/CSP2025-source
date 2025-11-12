#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace::std;
inline int read()
{
	int k(0);bool f(true);char ch(getchar());
	for(;ch<48||ch>57;ch=getchar())if(ch==45)f=false;
	for(;ch>=48&&ch<=57;ch=getchar())k=(k<<1)+(k<<3)+ch-48;
	return f?k:-k;
}
struct node
{
	int a,id,gp;
	bool operator<(const node k)
	const{return a>k.a;}
};
struct node2
{
	int val,id;
	bool operator<(const node2 k)
	const{return val<k.val;}
}u;
inline int hMAX(int a,int b,int c)
{
	int h[5]={a,b,c};
	sort(h,h+3);
	return h[1]-h[2];
}
inline node2 cMAX(int a,int b,int c)
{
	node2 h[5]={{a,1},{b,2},{c,3}};
	sort(h,h+3);
	return (node2){h[1].val,h[1].id};
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T(read()),n,x,y,z,ans,i;
	for(;T--;)
	{
		n=read();
		vector<node> a;
		vector<int> b(n+1,0);
		vector<node2> c(n+1,(node2){0,0});
		vector<bool> vis(n+1,false);
		priority_queue<node2> q[5];
		for(i=1;i<=n;i++)
		  x=read(),y=read(),z=read(),
		  b[i]=hMAX(x,y,z),
		  c[i]=cMAX(x,y,z),
		  a.emplace_back((node){x,i,1}),
		  a.emplace_back((node){y,i,2}),
		  a.emplace_back((node){z,i,3});
		sort(a.begin(),a.end());
		ans=0;
		for(auto i:a)
		{
			if(vis[i.id])continue;
			if(q[i.gp].size()==n/2)
			{
				u=q[i.gp].top();
				if(u.val>b[i.id])
				  q[i.gp].pop(),
				  q[i.gp].emplace((node2){b[i.id],i.id}),
				  q[c[u.id].id].emplace((node2){u.val,u.id}),
				  ans+=u.val+i.a;
				else
				  q[c[i.id].id].emplace((node2){b[i.id],i.id}),
				  ans+=c[i.id].val;
			}
			else
			  q[i.gp].emplace((node2){b[i.id],i.id}),
			  ans+=i.a;
			vis[i.id]=true;
		}
		printf("%d\n",ans);
	}
	return ~~(0-0);
}
