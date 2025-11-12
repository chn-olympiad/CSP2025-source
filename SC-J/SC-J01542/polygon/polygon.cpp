#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N= 5005,mod=998244353;
int arr[N],n,ans,vis[N];
void dfs(int u,int d,int ma,int sum){
	if(d>=3){
//		printf("%d %d %d\n",d,ma,sum);
		if(ma*2<sum)ans++;
	}
	for(int i=u;i<=n;i++){
		dfs(i+1,d+1,max(ma,arr[i]),sum+arr[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(0,0,0,0);//fang qi le ,bao sou ba
	cout<<ans/2%mod;
	return 0;
}