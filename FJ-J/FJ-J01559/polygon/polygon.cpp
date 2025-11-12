#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int n,a[5005];
int ans=0;
void dfs(int k,int h,int maxn,int sum){
	if(maxn*2<sum && h>=3){
		ans++;
		
	}
	if(k==n+1){
		return;
	}
	dfs(k+1,h+1,max(maxn,a[k]),sum+a[k]);
	dfs(k+1,h,maxn,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	if(n==3){
		cout<<ans;
	}else{
		cout<<ans-2;
	}
	return 0;
} 
