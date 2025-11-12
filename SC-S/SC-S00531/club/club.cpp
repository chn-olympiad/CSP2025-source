#include<bits/stdc++.h>
using namespace std;
int n,ma,T;
struct S{
	int a,b,c;
}r[20];
void dfs(int x,int a,int b,int c,int sum){
	if(x>n){
		ma=max(sum,ma);
		return;
	}
	if(a<(n>>1))dfs(x+1,a+1,b,c,sum+r[x].a);
	if(b<(n>>1))dfs(x+1,a,b+1,c,sum+r[x].b);
	if(c<(n>>1))dfs(x+1,a,b,c+1,sum+r[x].c);
}
bool cmp(S&a,S&b){
	return a.a-a.b>b.a-b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){	
		scanf("%d",&n),ma=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
		if(n>30){
			sort(r+1,r+n+1,cmp);
			for(int i=1;i<=(n>>1);i++)ma+=r[i].a;
			for(int i=(n>>1)+1;i<=n;i++)ma+=r[i].b;
		}else dfs(1,0,0,0,0);
		printf("%d\n",ma);
	} 
}