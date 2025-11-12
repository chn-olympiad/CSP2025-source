#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, m;
struct node{
	int id, val;
}a[105];

bool cmp(node a, node b){
	return a.val > b.val;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		a[i].id = i;
		cin >> a[i].val;		
	}	
	sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1;
	for(int i = 1; i <= n * m; i++){
		if(a[i].id == 1){
			cout << y << " " << x << endl;
			return 0;
		}
		if(y % 2){
			x++;
			if(x > n){
				x = n, y++;
			}
		}else{
			x--;
			if(x < 1){
				x = 1, y++;
			}
		}
	}
	return 0;
}
