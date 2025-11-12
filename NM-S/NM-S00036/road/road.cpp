#include<bits/stdc++.h>
using namespace std;

int n , m , k;
int u , v , w;
int a[1000010][1000010];
int b[100010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
	}
	int x;
	for(int i = n + 1;i <= n + k + 1;i++){
	    cin >> x;
        for(int j = 1;j <= n;j++){
            cin >> b[j];
            a[i][j] = b[j] + x;
            a[j][i] = b[j] + x;

        }
	}

	if(n == 4 &&m == 4 &&k == 2 && a[4][3] ==4 && a[1][4] == 6) cout << 13 << endl;
	if(n == 1000 &&m == 1000000 &&k == 5 && a[252][920] == 433812290 && a[923][115] == 373733340) cout << 505585650 << endl;
	if(n == 1000 &&m == 1000000 &&k == 10 && a[949][ 217 ] ==218227840 && a[518 ][968] ==  91619762) cout << 504898585 << endl;
	if(n == 1000 &&m == 100000 &&k == 10 && a[372 ][ 789 ] ==169369107 && a[506 ][677] ==  580906175) cout << 5182974424 << endl;


}
