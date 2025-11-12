#include<bits/stdc++.h>
using namespace std;
int n,a[5005],now,m,sum;
long long ans;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int t){
	if(x>now){
		return; 
	}
	for(int i=t;i<=n;i++){
		sum+=a[i];
		if(sum>a[m]&&x>1) ans++;
		dfs(x+1,i+1);
		sum-=a[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(m=1;m<=n-2;m++){
		now=n-m;
		dfs(1,m+1);
	}
	cout<<ans%998244353;
	return 0;
} 
