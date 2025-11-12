#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[5005];
bool vis[5005];
int i,cnt = 0,sum=0,ans=0,last=0,maxx=-1e9;
int n;
void dfs(int x){
	if(cnt >= i){
		if(sum>maxx*2){
			ans++;
			return ;
		} 
	}
	for(int i=x;i<=n;i++){
		vis[i] = true;
		cnt++;
		sum+=a[i];
		last = maxx;
		maxx = max(maxx,a[i]);
		dfs(i);
		vis[i] = false;
		cnt--;
		sum-=a[i];
		maxx = last;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			vis[j] = true;
			cnt++;
			sum+=a[j];
			last = maxx;
			maxx = max(maxx,a[j]);
			dfs(j);
			vis[j] = false;
			cnt--;
			sum-=a[j];
			maxx = last;
		}
	}
	ans%=998;
	ans%=244;
	ans%=353;
	cout << ans << endl;
	return 0;
} 
