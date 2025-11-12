#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int sum,ans;
void dfs(int x,int y){
	if(x>=3&&sum>a[y]*2){
		ans++;
		ans%=998;
		ans%=244;
		ans%=353;
	}
	if(y==n)return ;
	for(int i=y+1;i<=n;i++){
		sum+=a[i];
		dfs(x+1,i);
		sum-=a[i];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans;
	return 0;
}
