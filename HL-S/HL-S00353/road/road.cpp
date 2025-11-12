#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[1000010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    int u,v;
    for(int i = 1;i<=m;i++){
    	cin >> u >> v >> w[i];
	}
	int a = ceil(n*1.0/2)+1;
	sort(w+2,w+m+2);
	int ans = 0;
	for(int i = 1;i<=a;i++){
		ans+=w[i];
	}
	cout << ans;
	return 0;
}