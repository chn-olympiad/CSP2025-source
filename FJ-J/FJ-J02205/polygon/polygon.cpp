#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,ans;
void dfs(long long m,long long sum,long long maxx,long long x){
	if(m>=3&&sum>2*maxx){
		ans++;
	}
	if(m>=n){
		return ;
	}
	for(long long i=x+1;i<=n;i++){
		long long u=maxx;
		maxx=max(maxx,a[i]);
		dfs(m+1,sum+a[i],maxx,i);
		maxx=u;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}

