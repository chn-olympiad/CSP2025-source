#include<bits/stdc++.h>

using namespace std;

int n,m;
int a,b = 1;
int r,c;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> a;
	for(int i = 2 ; i <= n*m ; i++){
		int nums;
		cin >> nums;
		if(nums > a)b++;
	}
	if(b % n == 0)r = b / n;
	else r = b / n + 1;
	if(r % 2 == 1){
		if(b % n == 0)c = m;
		else c = b % n;
	}
	else {
		if(b % n == 0)c = 1;
		else c = n - (b % n) + 1;
	}
	cout << r << ' ' << c;
	return 0;
}
