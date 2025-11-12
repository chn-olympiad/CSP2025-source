#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5009;
int a[N];
int ans=0,n;
void dfs(int sum,int m,int z,int step){
	if(sum>=3&&z>m*2){
		
		ans++;
	}
	if(step>n){
		return;
	}
	dfs(sum+1,max(m,a[step]),z+a[step],step+1);
	dfs(sum,m,z,step+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,1);
	cout<<ans%998244353;
	return 0;
}
