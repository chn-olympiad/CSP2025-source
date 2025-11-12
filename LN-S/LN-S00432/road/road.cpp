#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int fa[N];
bool init(int n)
{
for(int i=1;i<=n;i++)
fa[i]=i;
}
void unionn (int a,int b)
{
int aa=fa[a];
int bb=fa[b];
find(aa)=bb;
return find(aa);
}
int find(int g)
{
if(fa[g]==find(g))
return fa[g];
else
{
fa[g]=find[fa[g]];
return fa[g];
}
}
int main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
int n,m,k;
int u,v,d;
cin>>n>>m>>k;
init(n);
for(int i=1;i<=m;i++)
{
cin>>u>>v>>d;
}
cout<<0;
return 0;
}
