#include<bits/stdc++.h>
using namespace std;

int n,a[5005],ans;
void dfs(int t,int count,int sum,int maxx){
	if(t==n+1){
		if(count>=3){
			if(sum>maxx*2){
				ans++;
				ans%=998244353;
			}
		}
		return;
	}
	dfs(t+1,count+1,sum+=a[t],a[t]);
	dfs(t+1,count,sum-=a[t],maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,-1);
	cout << ans;
	return 0;
}
