#include<bits/stdc++.h>

using namespace std;

const int N = 6010;
const int Modd = 998244353;

int n,a[N],ans;
bool vis[N];

void dfs(int l,int maxx,int summ){
	if(summ > maxx*2){
		ans++;
		ans = ans % Modd;
		return;
	}else{
		if(vis[l] == 0){
			for(int i = l;i <= n;i++){
				dfs(i+1,max(maxx,a[i]),summ+a[i]);
				dfs(i+1,maxx,summ);
			}
		}
		
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,0,0);
	cout << ans % Modd;
	return 0;
}