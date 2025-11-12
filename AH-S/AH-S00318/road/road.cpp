#include<bits/stdc++.h>
using namespace std;

int n, m, k, sum, mx, x;
string s;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin>>a>>b>>c;
	}
	for(int i = 1; i <= n + 1; i++){
		cin>>x;
		mx = max(mx, x);
		sum += x;
	}
	cout<<sum - mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
