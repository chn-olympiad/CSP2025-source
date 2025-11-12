#include<bits/stdc++.h>
using namespace std;
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i){
		int a,b,c;
		cin >> a >> b >> c;
		ans += c;
	}
	int a;
	cin >> a;
	for(int i = 0; i < k; ++i){
		for(int j = 0; j < m; ++j){
			int as[m];
			cin >> as[i];
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
