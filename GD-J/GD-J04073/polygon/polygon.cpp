#include<bits/stdc++.h>
using namespace std;
long long n,a[10010],ans,b[10010];
bool cmp(int x,int y){
	return x>y;
}
int dfs(int x,int cnt,int maxn,int cnt2){
	if(cnt>n){
		return 0;
	}
	if(cnt>=3){
		if(cnt2>maxn*2){
			ans++;
		}
	}
	for(int j=x+1;j<=n;j++){
		dfs(j,cnt+1,maxn,cnt2+a[j]);
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i],a[i]);
	}
	cout<<ans%998244353;
	return 0;
}
