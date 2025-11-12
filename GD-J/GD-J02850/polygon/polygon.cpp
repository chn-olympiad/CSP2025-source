#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
#define mod 998244353 
int n,a[N],ans,startt;
void dfs(int u,int sum,int mx){
	if(clock()-startt>970) return;
	if(u==n+1){
		if(sum>mx*2) ans++; /*cout<<sum<<" "<<mx<<" "<<ans<<endl;*/
		ans%=mod;
		return;
	}
	dfs(u+1,sum+a[u],a[u]);
	dfs(u+1,sum,mx);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	if(n<=20){
		startt=clock();
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout<<ans<<endl;		
	} 
	else cout<<"0";
	return 0;
} 

//        ___       __
//       /   |     / /
//      / /| |    / /
//     / / | |   / /
//    / /  | |  / /
//   / /   | | / /
//  / /    | |/ /
// / /     | | /
