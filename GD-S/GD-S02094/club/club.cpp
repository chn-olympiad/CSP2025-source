#include <bits/stdc++.h>

using namespace std;
    freopen("club.in","r","stdin");
    freopen("club.out","w","stdout");
   int a[max];
   cin>>a[max];
   int m_mem;
   
struct  js
{
	int x,v,w;
}
void tc(int  x)
{
	js pop[vis[x]+2],pop2[vis[x]+2];
	int cut=0;
	for(int i=0;i<=vis[x];i++){
		
		pop1[i].w=i;
		pop2[i].w=i;
		pop1[i].x=r;
		pop2[i].x=l;
		pop1[i].v=b[xu[i][x][r]];
		pop2[i].v=b[xu[i][x][l]];
		
	}
		sort(pop1+1,pop1+vis[x]+1,cmp);
		sort(pop2+1,pop2+vis[x]+1,cmp);
		for(int int i=1;j=1;i+j+m_mem<vis[x];)
		{
			if(pop1[i].v<pop2[i].v){
				vis[r]++;
				xu[vis[r]][r]=xu[pop[1].w][x];
			}
		}
return 0;
}
int main(){
   while(i--){
   int n,t;
   cin>>n>>t;
   cont<<a[i]d[i];
}
   return 0;
