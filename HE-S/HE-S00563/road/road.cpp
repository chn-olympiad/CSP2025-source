#include<bits/stdc++.h>
using namespace std;

int const MAXN = 1e6 + 5;
int u[MAXN],v[MAXN],w[MAXN],aj[MAXN],cj,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	cin >> cj;
	for(int i = 1; i <= n; i++)
	cin >> aj[i];
	sort(w+1,w+m+1);
	for(int i = 1; i<= m/2; i++)
	ans += w[i];
	cout <<ans;
}
