#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000+5;
int n;
int a[MAXN]; 
bool v[MAXN];
int ans=0;
void dfs(int stp,int sum,int cnt,int mxx,int k) {
	if (cnt>=3&&mxx*2<sum&&k) {
	    ans++;
	}
	if (stp>n) return;
	if (stp<=n) {
		dfs(stp+1,sum+a[stp],cnt+1,max(mxx,a[stp]),1);
		dfs(stp+1,sum,cnt,mxx,0);
	}
} 
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
    dfs(1,0,0,0,0);
	cout<<ans<<'\n';
	return 0;
}
