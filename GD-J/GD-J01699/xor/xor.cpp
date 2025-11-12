#include <bits/stdc++.h>
using namespace std;
int n,k,a[1005][1005];
int ans;
int dfs(int i){
	int j=i;
	while(j<=n){
		if(a[i][j]==k){
			ans++;
			return j-i+1;
		}
		j++;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i][i];
		if(i==1) continue;
		a[i-1][i]=a[i-1][i-1]^a[i][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(j==i+1) continue;
			int k=i,p=i+1;
			while(p<=j){
				a[i][j]^=a[k][p];
				k++;p++;
			}
		}
	}
	for(int i=1;i<=n;){
		i+=dfs(i);
	}
	cout <<ans;
	return 0;
}
