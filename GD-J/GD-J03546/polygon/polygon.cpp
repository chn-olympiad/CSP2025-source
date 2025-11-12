#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 5010;
int a[N];
long long ans;
int allmax;
void dfs(int maxx,int sum,int cnt,int u){
	if(u>n){
		if(cnt>=3&&sum>maxx*2) ans++;
		return;
	}
	dfs(maxx,sum,cnt,u+1);
	int nw = max(maxx,a[u]);
	dfs(nw,sum+a[u],cnt+1,u+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		allmax = max(allmax,a[i]);
	}
	if(allmax==1){
		for(int i = 3;i<=n;i++){
			long long s = 1;
			for(int j = n;j>=n-i+1;j--){
				s*=j;
			}
			for(int j = 2;j<=i;j++){
				s/=j;
			}
			ans+=s;
		}
	}
	else dfs(0,0,0,1);
	cout<<ans;
	return 0;
}
