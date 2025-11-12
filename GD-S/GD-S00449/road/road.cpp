#include <bits/stdc++.h>
using namespace std;
int r[100011][6],s[100011],s1[11];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,w = 0,ans = 0;
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++){
		for (int j = 0;j < 3;j++){
			cin >> r[i][j];
		}
		s[i] = r[i][2];
	}
	sort(s+1,s+m+1);
	for (int p = 0;i < k;i++){
		for (int q = 0;j < 5;j++){
			cin >> r[m+p][q];
		}
		s1[p] = r[0];
	}
	
	for (int l = 0;l < n;l++){
		w += s[l];
	}
	cout << w;
	fclose(stdin);
	fclose(stdout);
	return 0;
}