#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MOD 998244353
using namespace std;
int n,arr[5005],q[5005],ans=0;
int maxlen,cntl;
void dfs(int l,int r,int k,int res){	// I gonna TLE
	if(k>=cntl){
		if(res>2*arr[l]){
			ans++;ans%=MOD;
		}
		return;
	}
	for(int i=l+1;i<=r;i++){
		dfs(i,r,k+1,res+arr[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	sort(arr+1,arr+n+1);
	for(int i=3;i<=n;i++){
		cntl=i;
		dfs(0,n,0,0);
	}
	printf("%d",ans);
	return 0;
}
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
//I Love Nahida Forever
// Finished at 10:10  1h40min
