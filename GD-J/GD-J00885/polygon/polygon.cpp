#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f;
const int N = 1e5 + 10;
const int mod = 998244353;
#define LL long long

int n , a[5010] , f[5010];

vector<int> t[5010];

int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &a[i]);
	}
	sort(a + 1 , a + n + 1);
	if(n == 3){
		if(a[1] + a[2] > a[3]) cout << 1 << endl;
		else cout << 0 << endl;
	}else {
		cout << 0 << endl;
	}
	return 0;
}

/*


*/
