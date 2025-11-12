#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll maxn;
int T;
bool flaga=1;
struct node{
	int a,b,c,id;
}f[100005];
void dfs(int k,ll sum,int cnts,int cntk,int cntl){
	
	if(cnts>n/2||cntk>n/2||cntl>n/2) return ;
	if(k>n){
		maxn=max(maxn,sum);
		return ; 
	}
	dfs(k+1,f[k].a+sum,cnts+1,cntk,cntl);
	dfs(k+1,f[k].b+sum,cnts,cntk+1,cntl);
	dfs(k+1,f[k].c+sum,cnts,cntk,cntl+1);
}
bool cmp1(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.b>b.b;
}
ll aaa;
node s[100005];
node k[100005];
node l[100005];
int cnts,cntk,cntl;
int vis[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flaga=1;
		maxn=0;	
		aaa=0;
		bool flagb=1;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
			if(n>=200){
				aaa+=max(f[i].a,max(f[i].b,f[i].c));
			}
			f[i].id=i;
			if(f[i].b!=0||f[i].c!=0){
				flaga=0;
			}
			if(f[i].c!=0){
				flagb=0; 
			}
		}
		if(flaga){
			sort(f+1,f+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				maxn+=f[i].a; 
			}
		}
		else if(n<=200)
		dfs(1,0,0,0,0);
		else{
			maxn=aaa;
		}
		printf("%lld\n",maxn);
	}
	return 0;
}

