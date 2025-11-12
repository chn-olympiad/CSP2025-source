#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans;
const int mod=998244353;
int n;
int a[5005];
int dfs(int sum,int mx,int k,int cnt){
	if(k<=n){
		return (dfs(sum+a[k],max(mx,a[k]),k+1,cnt+1)+dfs(sum,mx,k+1,cnt))%mod;
	}
	else return sum>mx*2&&cnt>=3;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
//	for(int i=3;i<=n;i++){
//		for(int j=i-1;j>=1;j--){
//			int sum=0;
//			for(int k=j-1;k>=1;k--){
//				sum+=a[k];
//				if(a[j]+sum>a[i]){
//					ans=(ans+(1<<(k-1)))%mod;
//					sum=0;
//				}
//			}
//		}
//	}
//	cout<<ans;
	cout<<dfs(0,a[1],1,0);
	return 0;
}
