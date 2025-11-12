#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5005;
int arr[N];
int n,ans=0;
void dfs(int sum,int x,int cnt){//选择编号的总和，上一次选到第几个，选了几个 
	if(cnt>=3&&arr[x]*2<sum){
		ans=(ans+1)%mod;
	}
	if(x>n||n-x+1+cnt<3){
		return ;
	}
	for(int i=x+1;i<=n;++i){
		dfs(sum+arr[i],i,cnt+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
