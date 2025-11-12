#include<bits/stdc++.h>
using namespace std;
long long n,maxn;
long long a[5010];
long long ans;
void dfs(int sum,long long maxx,int k,int cur,int tot){
	if(k>tot){
		if(sum>2*maxx) ans++;
		return;
	}
	if(k+n-cur+1<tot) return;
	for(int i=cur+1;i<=n;i++){
		if(k+n-i+1<tot) break;
		dfs(sum+a[i],max(maxx,a[i]),k+1,i,tot);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(long long i=3;i<=n;i++){
			long long sumi=0;
			for(long long j=1;j<=i;j++){
				sumi*=(n-j+1);
				sumi/=i;
				sumi%=998244353;
			}
			ans+=sumi;
			ans%=998244353;
		}
		cout<<ans<<"\n";
	}
	else if(n<=500){
		for(int i=3;i<=n;i++){
			dfs(0,0,1,0,i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
