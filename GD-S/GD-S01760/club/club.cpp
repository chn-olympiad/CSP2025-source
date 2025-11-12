#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],sum[4],sum2,b[100005][4];
long long maxn;
bool vis[100005][4];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int cnt){
	if(cnt==n+1){
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(vis[i][j]){
					sum+=a[i][j];
				}
			}
		}
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(sum[i]<n/2){
			vis[cnt][i]=1;
			sum[i]++;
			dfs(cnt+1);
			vis[cnt][i]=0;
			sum[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		maxn=sum2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2||j==3){
					if(a[i][j]==0){
						sum2++;
					}
				}
			}
		}
		if(sum2==n*2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=n;j++){
					b[i][j]=a[j][i];
				}
			}
			sort(b[1]+1,b[1]+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				maxn+=b[1][i];
			}
			cout<<maxn<<"\n";
			continue;
		}
		memset(vis,0,sizeof(vis));
		dfs(1);
		cout<<maxn<<"\n";
	}
	return 0;
}
