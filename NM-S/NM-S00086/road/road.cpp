#include<bits/stdc++.h>
using namespace std;
struct node{
	        int zhong;
	        long long quan;
           };
int n,m,k,u,v;
long long ans,w,cs,zizi[15],jl[10055];
bool sf[10055];
vector<node> bian[10055];
int main()
 {
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=m;i++)
     {
		 scanf("%d%d%lld",&u,&v,&w);
		 bian[u].push_back({v,w});
		 bian[v].push_back({u,w});
     }
  for(int i=1;i<=k;i++)
     {
		scanf("%lld",&zizi[i]);
		for(int j=1;j<=n;j++)
		   {
			   scanf("%lld",&cs);
			   bian[n+i].push_back({j,cs+zizi[i]});
			   bian[j].push_back({n+i,cs+zizi[i]});
		   }
	 }
  for(int i=0;i<=n+k;i++)
     {
		 jl[i]=1e17;
     }
  jl[1]=0;
  for(int asdf=1;asdf<=n;asdf++)
     {
		int qwe=0;
		for(int i=1;i<=n+k;i++)
		   {
			if(sf[i]==false&&jl[i]<=jl[qwe]) qwe=i;   
		   }
		sf[qwe]=true;
		int bijiao=bian[qwe].size();
		if(qwe>n) {
			       asdf--;
			       for(int i=0;i<bijiao;i++)
			          {
						 bian[qwe][i].quan-=zizi[qwe-n]; 
					  }
		          }
		for(int i=0;i<bijiao;i++)
		   {
			   int zhou=bian[qwe][i].zhong,qua=bian[qwe][i].quan;
			   if(sf[zhou]==true) continue;
			   if(qua<jl[zhou]) jl[zhou]=qua;
		   } 
	 }
  for(int i=1;i<=n+k;i++)
     {
		if(sf[i]==true) ans+=jl[i];
	 }
  cout<<ans;
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
