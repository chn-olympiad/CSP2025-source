#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("club.in");
ofstream cout("club.out");
int t, n, lov[100001][3];
int dfs(int k, int a, int b, int c, int fin){
	if(k == n) return fin;
	int ans = 0;
	if(a<n/2) ans=max(ans,dfs(k+1,a+1,b,c,fin+lov[k][0]));
	if(b<n/2) ans=max(ans,dfs(k+1,a,b+1,c,fin+lov[k][1]));
	if(c<n/2) ans=max(ans,dfs(k+1,a,b,c+1,fin+lov[k][2]));
	return ans;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++)
			for(int j=0; j<3; j++)
				cin >> lov[i][j];
		cout << dfs(0, 0, 0, 0, 0) << endl;
	}
	return 0;
}
