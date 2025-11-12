#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL n,ans;
LL a[10000];

void dfs(LL id, LL maxL, LL sum){
	if(id>n){
		if(maxL*2 < sum){
			ans++;
			
		}return;
	}
	
	dfs(id+1,max(maxL,a[id]),sum+a[id]);
	dfs(id+1,maxL,sum);
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;  
	for(LL i=1;i<=n;i++){
		cin >> a[i];
	}
	
	dfs(1,0,0); 
	cout << ans%998244353 << '\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

