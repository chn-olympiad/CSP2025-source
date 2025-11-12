#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t, n, sum = 0, i[n][3];
	cin >> t;
	for(int cishu = 0; cishu < t; cishu++){
		cin >> n;
		for(int it = 0; it < n; it++){
			for(int is = 0; is < 3; is++){
			cin >> i[it][is];
			}
		}
	}
	return 0;
}
