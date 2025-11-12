#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],ans=0;
void dfs(int i,long long he,long long mx){
	if(he!=0&&he>2*mx){
		ans++;
		ans=ans%998244353;
	}
	if(i>n) return;
	dfs(i+1,he+a[i],max(mx,a[i]));
	dfs(i+1,he,mx);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
