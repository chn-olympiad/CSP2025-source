#include <bits/stdc++.h>
using namespace std;

long long n,a[5010],ans;
long long dfs(long long x,long long sum){
	if(a[x]<sum){
		ans=(ans+1)%998244353;
	}
	sum+=a[x];
	for(long long i=x+1;i<=n;i++){
		dfs(i,sum);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	stable_sort(a+1,a+1+n);
	dfs(0,0);
	cout << ans;
	return 0;
}
