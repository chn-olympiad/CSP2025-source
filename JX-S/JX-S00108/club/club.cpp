#include <iostream>
#include <algorithm>
using namespace std;
int const N = 201;
int const N2 = N>>1;
int as[N][3];
int n;
int dfs(int i,int a,int b,int c){
	if(i==n+1) return 0;
	int ans = 0;
	if(a<n/2)ans = max(ans,dfs(i+1,a+1,b,c)+as[i][0]);
	if(b<n/2)ans = max(ans,dfs(i+1,a,b+1,c)+as[i][1]);
	if(c<n/2)ans = max(ans,dfs(i+1,a,b,c+1)+as[i][2]);
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = 0;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++)cin >> as[i][0] >> as[i][1] >> as[i][2];
		int ans = dfs(1,0,0,0);
		cout << ans << endl;
	}
	return 0;
}