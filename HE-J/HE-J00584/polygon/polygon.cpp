#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int a[5005],vis[5005];
int dp[250][500][500];
void zbb(int sum,int maxx,int tot){
	if(tot>=n) return ;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			tot++;
			maxx=max(maxx,a[i]);
			if(sum+a[i]>2*maxx&&tot>=3&&dp[sum+a[i]][maxx][tot]==0){
					dp[sum+a[i]][maxx][tot]=1;
					ans++,ans%=998244353;
					//cout<<sum+a[i]<<" "<<maxx<<" "<<tot<<endl;
			}
			zbb(sum+a[i],maxx,tot);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    zbb(0,0,0);
    cout<<ans;
	return 0;
}
