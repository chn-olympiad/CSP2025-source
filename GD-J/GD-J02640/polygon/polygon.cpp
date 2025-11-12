#include <fstream>
using namespace std;
ifstream cin("polygon.in");
ofstream cout("polygon.out");
int n, cnt, len[5000];
int dfs(int k, int xu, int mx, int su){
	if(k == n) return (xu > 2) && (su > 2 * mx);
	return (dfs(k + 1, xu + 1, max(mx, len[k]), su
	+ len[k]) + dfs(k + 1, xu, mx, su)) % 998244353;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> len[i];
	cout << dfs(0, 0, 0, 0);
	return 0;
}
