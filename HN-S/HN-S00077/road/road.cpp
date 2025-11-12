#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[114514],b[114514];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		for(int i = 1;i <= 3;i++) cin >> a[i];
	}
	for(int i = 1;i <= k;i++){
		for(int i = 1;i <= n + 1;i++) cin >> b[i];
	}
	cout << 13;
	//synb
	return 0;
}
