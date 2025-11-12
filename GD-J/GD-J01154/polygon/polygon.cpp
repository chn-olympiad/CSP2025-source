#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long n;
long long ans=0;
const int mod=998244353;
void dfs(long long x,long long sum,long long cnt,long long mx,long long idx){
	if(x==cnt){
		if(sum>mx*2) {
			ans++;
			ans=ans%mod;
		}
		return ;
	}
	for(long long i=idx+1;i<=n;i++){
		dfs(x,sum+a[i],cnt+1,max(a[i],mx),i);
	}
}
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=3;i<=n;i++){
		dfs(i,0,0,0,0);
	}
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
