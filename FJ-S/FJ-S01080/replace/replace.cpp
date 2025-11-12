#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct ax{
	string s1 , s2;
}a[maxn];
int main(){
	freopen ("replace.in" , "r" , stdin);
	freopen ("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i++){
	    cin >> a[i].s1 >> a[i].s2;	
	}
	for (int i = 1 ; i <= q ; i++){
		bool flag =0;
		string t1 , t2;
		cin >> t1 >> t2;
		for (int i = 1 ; i <= n ; i++){
			if ((t1 == a[i].s1 && t2 == a[i].s2) || (t1 == a[i].s2 && t1 == a[i].s2)){
				cout << 2;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
	        cout << 0;       
	}
	return 0;
}
