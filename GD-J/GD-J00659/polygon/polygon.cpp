#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
long long f[25],ans;
long long dp[1000005];
long long vis[1000005];
int a[maxn];
int n,sum;
bool flag1,flag2;
//inline long long Cty(int n,int m){
//	return f[n]/f[n-m];
//}
//void dfs(int S,int sum){
//	int T;
//	vis[S] = 1;
//	for(int i = 0;i<n;i++)if(S&(1<<i)){
//		if(!vis[T])dfs(T,sum-a[i]);
//		dp[S]
//	}
//}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)cout<<0,exit(0);
	for(int i = 0;i<n;i++){
		cin>>a[i],sum+=a[i];
	}
	sort(a,a+n);
	if(n<=3&&a[n-1]<=10){
		if(a[0]+a[1]>a[2])cout<<1,exit(0);
	}
//	if(a[n]==1){
//		
//	}
	if(n<=20){
		for(int S = 0;S<=(1<<n)-1;S++){
//			cout<<S<<'\n';
			int num = 0,cnt = 0,mx = -1;
			for(int i = 0;i<n;i++)if(S&(1<<i)){
				num++;
				cnt+=a[i];
				mx = max(mx,a[i]);
			}
//			cout<<num<<" "<<cnt<<" "<<mx<<'\n';
			if(num<3)continue;
//			cout<<S<<'\n';
			if(mx<cnt-mx)ans++;
		}
		cout<<ans;
	}
}
