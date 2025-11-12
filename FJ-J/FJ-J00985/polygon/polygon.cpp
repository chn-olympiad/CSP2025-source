#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353,N = 5005;
int n,ans,mid;
int a[N],top;
struct Node{
	int k, mx, len;
};
vector <Node> v;
void dfs(int id,int k,int mx,int len){
	if(id == mid + 1){
		v.push_back({k,mx,len});
		return;
	}
	dfs(id + 1,k,mx,len);
	dfs(id + 1,k + 1,max(mx,a[id]),len + a[id]);
}
void dfs1(int id,int k,int mx,int len){
	if(id == n + 1){
		for(int i = 0; i < v.size(); i++){
			if(v[i].k + k >= 3 && v[i].len + len > 2 * max(mx,v[i].mx)){
				ans = (ans + 1) % mod;
			}
		}
		return;
	}
	dfs1(id + 1,k,mx,len);
	dfs1(id + 1,k + 1,max(mx,a[id]),len + a[id]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	mid = n / 2;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1,0,0,0);
	dfs1(mid + 1,0,0,0);
	cout << ans;
	return 0;
}
