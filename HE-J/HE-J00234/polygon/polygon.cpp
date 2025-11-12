#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
long long ans=0;
const int mod=998244353;
void dfs(long long x,long long cnt,long long sum,long long ma){
	if(x==n+1){
		if(sum>2*ma&&cnt>=3){
			ans++;
		}
		return ;
	}
	dfs(x+1,cnt+1,sum+a[x],max(ma,a[x]));
	dfs(x+1,cnt,sum,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5  2 2 3 8 10
*/
