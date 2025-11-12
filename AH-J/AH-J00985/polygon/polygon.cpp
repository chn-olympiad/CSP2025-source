#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5005],ans,vis[5005];
void dfs(LL sum,LL cur,LL maxn,LL x,LL pre){
	if(cur>x){
		if(sum>2*maxn){
			ans++;
		}
		return ;
	}
	for(LL i=pre+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(sum+a[i],cur+1,max(maxn,a[i]),x,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++)
		cin>>a[i];
	for(LL i=3;i<=n;i++){
		dfs(0,1,0,i,0);
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
