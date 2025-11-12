#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, f;
struct Stu{
	ll a;
	bool b = 0;
}stu[101];
bool cmp(Stu x, Stu y){
	return x.a > y.a;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	stu[1].b = 1;
	for(int i = 1; i <= n*m; i++) cin >> stu[i].a;
	stable_sort(stu+1, stu+n*m+1, cmp);
	for(int i = 1; i <= n*m; i++){
		if(stu[i].b){
			if(i % n == 0){
				cout << i / n << ' ';
				if((i/n)%2 == 0) cout << 1;
				else cout << n;
			} 
			else{
				cout << i / n + 1 << ' ';
				if((i/n+1)%2 == 0){
					cout << n-(i%n)+1;
				}
				else cout << i % n;
			} 
			break;
		}
	}
	return 0;
}
