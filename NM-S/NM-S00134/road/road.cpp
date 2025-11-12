#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll maxx=-1,ans=0,w[10005][10005],jian[6];
void shua(ll q,int pos)
{int t=5;
 while(pos<=t-1) {jian[t]=jian[t-1];t--;}
 jian[pos]=q;
}
int main()
{freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
 scanf("%d%d%d",&n,&m,&k);
 if(k==0) {
 for(int i=1;i<=m;i++)
    {int u,v;
	 ll c;
	 scanf("%d%d",&u,&v);
	 cin>>c;
	 if(w[u][v]==0||w[u][v]>c) w[u][v]=c;
	 }
 for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
       ans+=w[i][j];
 cout<<ans<<endl;return 0;}
 for(int i=1;i<=m;i++)
    {int u,v;
	 ll c;
	 scanf("%d%d",&u,&v);
	 cin>>c;
	 if(w[u][v]==0||w[u][v]>c) {w[u][v]=c;
                                for(int i=1;i<=5;i++)
                                    if(c>=jian[i]) shua(c,i);
                                }
	 }
 for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
       ans+=w[i][j];
 for(int i=1;i<=5;i++)
    ans-=jian[i];
 cout<<ans<<endl;
 return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],p[11][10005],ans=0,maxx=-1,rcd=1,con[10005][10005];
bool v[10005],start=true;
struct node
{int u,v,w;
}edge[1000005];
struct node1
{int c,p[10005];
 bool vis=true;
}xz[11];
bool cmp(node1 a,node1 b)
{return a.c>b.c;
}
void attach(node d)
{for(int i=1;i<=n;i++)
    {if(con[d.u][i]) v[i]=true;
     if(con[d.v][i]) v[i]=true;
     }
}
void change(int h)
{if(h>n) {ans=max(maxx,ans);return;}
 /*
 int tmp;
 if(rcd>k) tmp=edge[h].w;
   else tmp=min(xz[rcd].p[edge[h].u]+xz[rcd].p[edge[h].v]+xz[rcd].c,edge[h].w);

 if(!v[edge[h].u]&&!v[edge[h].v]&&start) {start=false;v[edge[h].u]=v[edge[h].v]=true;}
 if(v[edge[h].u]||v[edge[h].v]) {v[edge[h].u]=v[edge[h].v]=true;attach(edge[h]);}
 con[edge[h].u][edge[h].v]=true;
 printf("h=%d\n",h);
 int tmp=min(xz[rcd].p[edge[h].u]+xz[rcd].p[edge[h].v]+xz[rcd].c,edge[h].w);
 maxx+=tmp;
 if(xz[rcd].p[edge[h].u]+xz[rcd].p[edge[h].v]+xz[rcd].c<edge[h].w) {rcd++;printf("%d %d\n",edge[h].u,edge[h].v);}
 change(h+1);
 maxx-=tmp;
 if(xz[rcd].p[edge[h].u]+xz[rcd].p[edge[h].v]+xz[rcd].c<edge[h].w) rcd--;
}
int main()
{freopen("road1.in","r",stdin);
 //freopen("road.out","w",stdout);
 scanf("%d%d%d",&n,&m,&k);
 for(int i=1;i<=m;i++)
    scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
 for(int i=1;i<=k;i++)
    {scanf("%d",&xz[i].c);
     for(int j=1;j<=n;j++) scanf("%d",&xz[i].p[j]);
     }
 sort(xz+1,xz+10,cmp);
 for(int i=1;i<=m;i++)
    {memset(v,0,sizeof(v));
     memset(con,0,sizeof(con));
     change(i);
     }
 printf("%d\n",ans);
return 0;
}
*/
