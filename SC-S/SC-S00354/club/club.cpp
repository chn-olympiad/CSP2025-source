#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn][3];
int n;
ll ans;
int c[3];
void dfs(int num,ll ans1){
	if(num==n){
		ans=max(ans,ans1);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i]<n/2){
			c[i]++;
			dfs(num+1,a[num+1][i]+ans1);
			c[i]--;
		}
	}
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		if(n<=200){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=3;i++)c[i]=0;
 		for(int i=1;i<=n;i++)
 			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
		dfs(0,0);
		printf("%d\n",ans);
		}else{
			ans=0;
			ll f[maxn];
			int tot=0;
			for(int i=1;i<=n;i++)
 				for(int j=1;j<=3;j++){
 					scanf("%d",&a[i][j]);
 					if(j==1)f[++tot]=a[i][j];
				 }
			sort(f+1,f+1+tot,cmp);
			for(int i=1;i<=n/2;i++)ans+=f[i];
			printf("%d\n",ans);
		}
		
	}
	return 0;
} 