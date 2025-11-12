#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int dfs(int maxn,int i,int l,int s,int solve){
	solve=solve%998244353;
	if (i>n){
		return solve;
	}
	int ln=l+a[i],max1=max(maxn,a[i]),solven=solve,sn=s+1;
	if (ln>max1*2 && sn>=3){
		solven+=1;
	}
	return dfs(maxn,i+1,l,s,solve)+dfs(max1,i+1,ln,sn,solven);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << dfs(0,1,0,0,0);
	return 0;
}

