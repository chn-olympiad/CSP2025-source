#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 5e3+1;
int n;
int a[N];
long long cnt;
bool vis[N];
void dfs(int now){
	if(now == n+1){
		long long sum = 0,maxn = -1e18,used = 0;
		for(int i = 1;i<=n;i++){
			if(vis[i]){
				sum+=a[i];
				maxn = max(maxn,static_cast<long long>(a[i]));
				used++;
			}
		}
		if(used>=3&&sum>2*maxn){
			cnt++;
		}
		return;
	}
	vis[now] = true;
	dfs(now+1);
	vis[now] = false;
	dfs(now+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	dfs(1);
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
