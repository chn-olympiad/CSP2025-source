#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 5;
int n,m;
int x,y;
int cnt = 0;
int a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	cnt = a[1];
	int p = n * m;
	sort(a + 1,a + p + 1,greater<int>());
	x = 1,y = 1;
	for(int i = 1;i <= n * m;i++){
		if(a[i] == cnt){
			break;
		}else{
			if((y == n && x % 2 == 1) || (y == 1 && x % 2 == 0)){
				x++;
			}
			else if(x % 2 == 1){
				y++;
			}else{
				y--;
			}
		}
	}
	cout << x << " " << y;
	return 0;
}
