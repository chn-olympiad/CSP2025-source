#include<bits/stdc++.h>
using namespace std;
int n,m,a,vis[520],sum=0;
string s;
void dfs(int x){
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(x==n)sum++;
			else dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> a;
	}
	dfs(1);
	cout << sum%998244353;
	return 0;
}
