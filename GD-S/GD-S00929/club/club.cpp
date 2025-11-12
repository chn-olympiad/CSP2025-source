#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n,flag2,flag3;
ll ans,b[N],a[N][10];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,ll sum,int g1,int g2,int g3){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(g1+1<=n/2)
		dfs(x+1,sum+a[x][1],g1+1,g2,g3);
	if(g2+1<=n/2)
		dfs(x+1,sum+a[x][2],g1,g2+1,g3);
	if(g3+1<=n/2)
		dfs(x+1,sum+a[x][3],g1,g2,g3+1);
	
}
void sol(){
	if(!flag2&&!flag3){
		for(int i=1;i<=n;i++){
			b[i]=a[i][1];
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=b[i];
		}
		printf("%lld\n",ans);
		return;
	}
	if(!flag3){
		for(int i=1;i<=n;i++){
			ans+=max(a[i][1],a[i][2]);
		}
		printf("%lld\n",ans);
		return;
	}
	dfs(1,0,0,0,0);
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		flag2=0;
		flag3=0;
		ans=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][2]) flag2=1;
			if(a[i][3]) flag3=1;
		}
		}
		sol();
	}
} 
