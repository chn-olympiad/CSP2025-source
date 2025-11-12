#include <bits/stdc++.h>
using namespace std;
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
int T,n;
struct st
{
	int id,val;
};
struct p
{
	int to,l;
	int val;
};
long long sum;
vector <st>v[4];
vector <p> q,cl[100005];
bool cmp(p a,p b)
{
	return a.l>b.l;
}
void pushin(int x,int xv,int xl)
{
	int y=cl[x][xv].to;
	v[y].push_back({x,xv});
	for(int i=v[y].size()-1;i>=0;i--)
	{
		if(cl[v[y][i-1].id][v[y][i-1].val].l>cl[v[y][i].id][v[y][i].val].l)
		{
			swap(v[y][i-1].id,v[y][i].id);
			swap(v[y][i-1].val,v[y][i].val);
		}
	}
}
bool check(int x,int xv,int xl)
{
	int y=cl[x][xv].to,z=-1,w,wv;
	int zl=0;
	for(int i=0;i<v[y].size();i++)
	{
		w=v[y][i].id;
		wv=v[y][i].val;
		if(xl+cl[w][wv+1].l>=cl[w][wv].l&&zl<xl+cl[w][wv+1].l-cl[w][wv].l)
		{
			zl=xl+cl[w][wv+1].l-cl[w][wv].l;
			z=i;
		}
	}
	if(z!=-1)
	{
		sum+=zl;
		w=v[y][z].id;
		wv=v[y][z].val;
		v[y][z].id=x;
		v[y][z].val=xv;
		pushin(w,wv,cl[w][wv].l);
		return 1;
	}else
	{
		return 0;
	}
} 
void add(int x,int xv)
{
	 
	int y=v[cl[x][xv].to][0].id,yv=v[cl[x][xv].to][0].val;
	if(xv>=3)
	{
		return ;
	}
	if(v[cl[x][xv].to].size()<n/2)
	{
		pushin(x,xv,cl[x][xv].l);
		sum+=cl[x][xv].l;
	}else if(cl[y][yv].l<cl[x][xv].l)
	{
		sum-=cl[y][yv].l;
		sum+=cl[x][xv].l;
		v[cl[x][xv].to].erase(v[cl[x][xv].to].begin());
		pushin(x,xv,cl[x][xv].l);
	}else 
	{
		if(!check(x,xv,cl[x][xv].l))
		{
			add(x,xv+1);
		}
	}
}
void get()
{
	scanf("%d",&n);
	long long a,b,c;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		q.push_back({1,a,0});
		q.push_back({2,b,0});
		q.push_back({3,c,0});
		sort(q.begin(),q.begin()+3,cmp);
		for(int j=0;j<3;j++)
		{
			cl[i].push_back({q[j].to,q[j].l,j});
		}
		q.erase(q.begin(),q.end());
		add(i,0);
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)cout<<i<<":"<<cl[i][j].to<<" "<<cl[i][j].l<<endl;
	}
	*/
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T)
	{
		T--;
		v[1].erase(v[1].begin(),v[1].begin()+v[1].size());
		v[2].erase(v[2].begin(),v[2].begin()+v[2].size());
		v[3].erase(v[3].begin(),v[3].begin()+v[3].size());
		n=0;
		sum=0;
		get();
		printf("%lld\n",sum);
	}
	return 0;
}
