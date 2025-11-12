#include<bits/stdc++.h>
using namespace std;
const int N = 1e4;
const int M = 1e3;
int t[N][N];
string str[M][M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> str[i][1] >> str[i][2];
		for(int j = 1; j <= q; j++){
			cin >> t[j][1] >> t[j][2];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
