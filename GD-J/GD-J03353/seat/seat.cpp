#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct st{
	int val, id;
	bool operator < (const st & X) const{
		return val > X.val;
	} 
}a[N];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i].val;
		a[i].id = i; 
	}
	sort(a+1, a+n*m+1);
	int idx;
	for(int i = 1;i <= n*m;i++){
		if(a[i].id == 1) {
			idx = i;
			//printf("[Dubug] Found rate = %d\n", idx);
			break;
		}
	}
	if(((idx-1)/n+1) % 2 == 1){
		cout << (idx-1)/n+1 << ' ' << (idx-1)%n+1;
	}
	else{
		cout << (idx-1)/n+1 << ' ' << n-(idx-1)%n; 
	}
} 
