#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5123];
long long ans;


void dfs(int x,int id,int sum,int la){
	if(id>x){
		if(sum>2*a[la]) ans++;
		return;
	}
	for(int i=la+1;i<=n;i++){
		dfs(x,id+1,sum+a[i],i);
	}
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,1,0,0);
	}
	cout << ans%mod;
	return 0;
}
