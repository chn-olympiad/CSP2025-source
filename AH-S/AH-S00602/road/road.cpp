#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k;
long long ans;
long long c[N][N];
struct DATA{
  long long u,v=0,w=INT_MAX;
}a[N][N];
map <long long,long long> q;
vector<DATA> add;
int find(int x)
{
if(x!=q[x]) return find(q[x]);
return x;
}
bool cmp(DATA a,DATA b)
{
  return a.w<b.w;
}
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++) q[i]=i;
  for(int i=1;i<=m;i++)
  {
   long long x,y,z;
   cin>>x>>y>>z;
   a[x][y].w=a[y][x].w=min(a[x][y].w,z);
  }
  for(int i=1;i<=k;i++)
  {
	long long p;
   cin>>p;
   for(int j=1;j<=n;j++)
   cin>>c[i][j];
   for(int j=1;j<=n;j++)
    for(int t=1;t<=n;t++)
    {
     a[j][t].w=a[t][j].w=min(a[t][j].w,p+c[i][j]+c[i][t]);
     a[j][t].u=j;
     a[j][t].v=t;
     a[t][j].u=t;
     a[t][j].v=j;
 }
} 
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      a[i][j].w=a[j][i].w=min(a[i][j].w,a[i][k].w+a[k][j].w);
  for(int i=1;i<=n;i++)
   for(int j=i+1;j<=n;j++)
   if(a[i][j].v!=0)add.push_back(a[i][j]);
  sort(add.begin(),add.end(),cmp);
  int l=add.size();
  for(int i=0;i<l;i++)
  {
   long long e=find(q[add[i].u]),o=find(q[add[i].v]);
   if(e!=o) ans+=add[i].w,q[add[i].u]=o;
   else {break;}
  }
  cout<<ans;
  return 0;
}
