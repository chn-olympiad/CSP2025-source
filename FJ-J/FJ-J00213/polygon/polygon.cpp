#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
void dfs(long long x,long long step,long long maxn,long long f){
	if(step>=3 && f>maxn*2){
		ans++;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,step+1,max(maxn,a[i]),f+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i],a[i]);
	}
	printf("%lld",ans);
	return 0;
}
