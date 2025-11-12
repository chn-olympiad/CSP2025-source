#include<bits/stdc++.h>
using namespace std;
long long cnt=1,ans,n,a[5005];
const int M=998244353;
void dfs(long long k,long long ma,long long sum,long long cnt){
	if(k==n+1){
		if(cnt>=3&&sum>2*ma)ans++;
		ans%=M;
		return;
	}
	dfs(k+1,ma,sum,cnt);
	dfs(k+1,max(ma,a[k]),sum+a[k],cnt+1);
}
long long fun(long long k){
	long long t=1,l=1;
	for(int i=1;i<=k;i++){
		t*=i;
		t%=M;
	}
	for(int i=1;i<=n-k;i++){
		l*=i;
		l%=M;
	}
	return cnt/t/l;
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
	}
	if(n<=30){
		dfs(1,0,0,0);
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=cnt*i;
		cnt%=M;
	}
	for(long long i=3;i<=n;i++){
		ans+=fun(i);
		ans%=M;
	}
	cout<<ans<<'\n';
	return 0;
}
