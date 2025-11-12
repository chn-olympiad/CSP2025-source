#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],x,cnt=1,ans=0;
void dfs(long long maxn,long long cnt,long long sum,long long s){
	if(cnt>n){
		if(maxn*2<sum&&s>=3){
			ans++;
		}
		return;
	}
	dfs(max(maxn,a[cnt]),cnt+1,sum+a[cnt],s+1);
	dfs(maxn,cnt+1,sum,s);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
}

