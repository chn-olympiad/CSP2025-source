#include<bits/stdc++.h>
using namespace std;
int ans;
int n,a[5005],vis[5005];
void dfs(int sum,int cnt,int ma,int e){
//	cout<<sum<<" "<<cnt<<" "<<ma<<endl;
	if(sum>2*ma&&cnt>=3){
		ans++;
	}
	if(cnt==6)return;
	for(int i=e;i<=n;i++){

		if(vis[i]==0){
			vis[i]=1;
			dfs(sum+a[i],cnt+1,max(ma,a[i]),i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,-1,1);
	cout<<ans;
	return 0; 
} 
