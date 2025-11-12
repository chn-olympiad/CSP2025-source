#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int ans=0,n,a[N],vis[N];
void dfs(int sum,int maxn,int d,int vis[]){
	if(d==0&&sum>2*maxn){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>maxn&&vis[i]==0){
			vis[i]=1;
			return dfs(sum+=a[i],a[i],d-1,vis);
		}else if(a[i]<=maxn&&vis[i]==0){
			vis[i]=1;
			return dfs(sum+=a[i],maxn,d-1,vis);
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
	for(int j=3;j<=n;j++){
		dfs(0,0,j-1,vis);
	}
	cout<<ans%998244353;
	return 0;
}
