#include <bits/stdc++.h>
using namespace std;
int t;
long long ans = 0;
const int maxn = 1e5 + 5;
struct s{
	int a , b , c;
}sb[maxn];

bool cmp(s x , s y){
	return x.a > y.a;
}
int main(){
     freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while (t--){
		ans = 0;
		int n;
		cin >> n;
		int un = n / 2;
		for (int i = 1 ; i <= n ; i++){
			cin >> sb[i].a >> sb[i].b >> sb[i].c;
		}
		if (n == 2){
			cout << max(sb[1].a + max(sb[2].b , sb[2].c) , max(sb[1].b + max(sb[2].a , sb[2].c) , sb[1].c + max(sb[2].b , sb[2].a)));
		    return 0;
		}
		if (sb[2].b == sb[2].c && sb[2].b == 0 && sb[1].b == sb[1].c && sb[1].b == 0){
			sort (sb + 1 , sb + n + 1 , cmp);
			for (int i = 1 ; i <= un ; i++){
				ans += sb[i].a; 
			}
		}
		cout << ans << endl;
	} 
	return 0;
} 
