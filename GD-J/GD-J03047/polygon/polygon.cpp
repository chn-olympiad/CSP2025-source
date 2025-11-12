#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int maxn=-1000000,ans=0,n,a[5010],sum=0,maxx;
//x 当前下标		b 剩余所需边数		n 小木棍总数 

void dfs(int x,int b){
	if(x>n){
		return;
	}
	for(int i=x;i<=n-b;i++){
		sum+=a[i];
		if(a[i]>maxn){
			maxx=maxn;
			maxn=a[i];
		}
		if(b==0){
			if(sum>maxn*2)
				ans++;
		}
		dfs(i+1,b-1);
		sum-=a[i];
		maxn=maxx;
	}
	return;
	
}

main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i-1);
	}
	cout<<ans%MOD;
	return 0;
}
