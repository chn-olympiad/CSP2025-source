#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
typedef long long ll;
using namespace std;
const int N=1e5+91,G=5e2+9,inf=0x7fffffff;
struct node
{
	int l,mo;
};
vector<node> G[N];
vector<node> M[N][11];
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("rond.out","w",stdout);
	f(i,1,m)
	{
		int x,y,m;
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&m);
		G[x].l.push_back(y);
		G[y].mo.push_back(x);
	}
	f(i,1,k)
	{
		int l;
		scanf("%d",&l);
		M[i][0][0]=l;
		f(j,1,m)
		{
			scanf("%d",&l);
			M[i][j].l.push_back(l);
		}
	}
	return 0;
}






















































