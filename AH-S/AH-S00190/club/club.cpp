#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct st{
	int a,b,c,id;
}a[N];
int n,f[N],used[N][4];
int dfs(int p,int x,int y,int z,int ans){
	int maxn=0;
	if(p==n+1){
		return ans;
	}
	if(x<n/2)	maxn=max(maxn,dfs(p+1,x+1,y,z,ans+a[p].a));
	if(y<n/2)	maxn=max(maxn,dfs(p+1,x,y+1,z,ans+a[p].b));
	if(z<n/2)	maxn=max(maxn,dfs(p+1,x,y,z+1,ans+a[p].c));
	return f[p]=maxn;
}
void work1(){
	printf("%d\n",dfs(1,0,0,0,0));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			f[i]=0;
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			a[i].id=i;
		}
		work1();
	}
	return 0;
}
