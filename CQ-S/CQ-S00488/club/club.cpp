#include<bits/stdc++.h>
using namespace std;
int a[20005][4],sum[4],n,b[20005],ans,num;
void dfs(int k){
	if(k>n){
		if(sum[1]>n/2) return;
		if(sum[2]>n/2) return;
		if(sum[3]>n/2) return;
		ans=max(ans,num);
		return;
	}for(int i=1;i<=3;i++){
		b[k]=i;
		num+=a[k][i];
		sum[i]++;
		dfs(k+1);
		sum[i]--;
		num-=a[k][i];
	}
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		num=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}

