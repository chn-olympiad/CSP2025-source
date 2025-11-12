#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],cnt;
void dfs(long long i,long long maxx,long long summ,long long cs){
	if(i==n){
		if(2*maxx<summ&&cs>=3){
			cnt=cnt+1%998244353;
		}
		return;
	}
	dfs(i+1,(max(a[i+1],maxx)),summ+a[i+1],cs+1);
	dfs(i+1,maxx,summ,cs);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,a[1],a[1],1);
	dfs(1,0,0,0);
	printf("%lld",cnt);
	return 0;
}
