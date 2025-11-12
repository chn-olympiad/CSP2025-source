#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 998224353;
int n;
int a[5005];
ll ans ;
void dfs(int t,ll s,int mx,int sz){
	if(t>n){
		if(sz>=3&&s>mx*2){
			ans++;
			ans %= M;
		}return;
	}
	dfs(t+1,s+a[t],max(mx,a[t]),sz+1);
	dfs(t+1,s,mx,sz);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++)cin >>a[i];
	bool flag = 1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)flag = 0;
	}if(flag==1){
		cout << ((1LL*(n-1)*(n-2))%M)/2;
	}else{
		dfs(1,0,0,0);
		cout <<ans;
	}fclose(stdin);
	fclose(stdout);
	return 0;
} 
