#include<bits/stdc++.h>
using namespace std;
int mod= 998244353;
int n;
int r[5010];
long long ans=0;
bool check(int x,int y) {
	//cout<<x<<" "<<y<<endl;
	return x>2*y;
}
void dfs(int x,int sumq,int maxq,int cnt) {
	if(x>n) {
		return;
	}
	dfs(x+1,sumq,maxq,cnt);//不选当前项
	cnt++;
	sumq+=r[x];
	maxq=max(maxq,r[x]);
	if(cnt>=3&&check(sumq,maxq)) {
		ans++;
		ans%=mod;
		//cout<<sumq<<" "<<maxq<<endl;
	}
	dfs(x+1,sumq,maxq,cnt);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>r[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
}
