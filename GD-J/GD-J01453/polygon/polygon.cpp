#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+15,mod=998244353;
int n,a[N],ans;
bool vis[N];
void dfs(int cur,int sum,int maxn,int x){
	if(cur>n) return;
	if(sum>maxn*2){
		ans=(ans+1)%mod;
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(cur+1,sum+a[i],a[i],i);
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
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<ans%mod;
	return 0;
} 
