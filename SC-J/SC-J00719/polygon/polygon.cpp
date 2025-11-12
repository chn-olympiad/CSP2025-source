#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,sum,maxn = -1,m,as[5005];
bool bj[5005];
void dfs(int x){
	if(sum>2*maxn&&m>=3){
		ans = (ans+1)%998244353;
	}
	if(x==n) return;
	for(int i=x+1;i<=n;i++){
		if(!bj[i]){
			bj[i] = 1;
			int bfmax = maxn;
			maxn = max(maxn,a[i]);
			sum+=a[i];
			m++;
			as[x+1] = a[i];
			dfs(i);
			bj[i] = 0;
			maxn = bfmax;
			m--;
			sum-=a[i];
			as[x+1] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0);
	cout<<ans;
	return 0; 
}