//DP
/*dp[i]:第i个人对 

dp[i][j]:
前i个人对 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][5],cnt[5],tot[N];
int ans=0;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int i,int j,int k){
	if(i==n){
		ans=max(ans,k);
		return;
	}
	for(int ne=1;ne<=3;ne++){
		if(cnt[ne]<=n/2-1){
			cnt[ne]++;
			dfs(i+1,ne,k+a[i+1][ne]);
			cnt[ne]--;
		}
	}
}
bool f=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		f=1;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			if(!(a[i][2]==a[i][3]&&a[i][2]==0)){
				f=0;
				break;
			}
		}
		int t[n+1]; 
		for(int i=1;i<=n;i++){
			t[i]=a[i][1];
		}
		ans=0;
		if(f==1){
			sort(t+1,t+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=t[i];
			}
			cout<<ans<<endl;continue;
		}
		
		if(n==2){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(j!=k){
						ans=max(ans,a[1][j]+a[2][k]);
					}
				}
			}
		} 
		else{
			for(int j=1;j<=3;j++){
				cnt[j]++;
				dfs(1,j,a[1][j]);
				cnt[j]--;
			}
		}
		printf("%d\n",ans);
	} 
	
}
