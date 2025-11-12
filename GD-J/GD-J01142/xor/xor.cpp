#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=5e5+5;
struct Tree
{
	int son[maxn*20][2],deep[maxn*20],val[maxn*20],tot,root;
	void insert(int &x,int fa,int v)
	{
		if(!x)x=++tot,deep[x]=deep[fa]+1;
		if(deep[x]>21)
		{
			val[x]++;
			return;
		}
		if((v>>(21-deep[x]))&1)
			insert(son[x][1],x,v);
		else insert(son[x][0],x,v);
	}
	void update(int x,int v)
	{
		if(!x||!v)return;
		update(son[x][1],v);
		update(son[x][0],v);
		if((v>>(21-deep[x]))&1)
			swap(son[x][0],son[x][1]);
	}
	bool find(int x,int v)
	{
		if(!x)return false;
		if(deep[x]>21)return val[x]!=0;
		if((v>>(21-deep[x]))&1)
			return find(son[x][1],v);
		else return find(son[x][0],v);
	}
}T;
int n,k,a[maxn],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		T.update(T.root,a[i]);
		T.insert(T.root,0,a[i]);
		if(T.find(T.root,k))
		{
			ans++;
			T.root=0;
		}
	}
	printf("%d",ans);
	return 0;
}
