#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x, ans = 0;
	while (cin >> x){
		if (rand() % 2 == 0){
			ans += x;
		}
	}
	cout << ans;
	return 0;
}
