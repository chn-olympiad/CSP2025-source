#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
int n;
int a[5005];
void dfs(int x,int k,int sum,int ma){
	if(x>n+1)return;
	if(k>n)return;
	dfs(x+1,k+1,sum+a[x],a[x]);
	dfs(x+1,k,sum,ma);
	if(sum>ma*2){
		if(k>=3&&a[x-1]==ma)ans++;
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,-1);
	cout<<ans;
	return 0;
} 
