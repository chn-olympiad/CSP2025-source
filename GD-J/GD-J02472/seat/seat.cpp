#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
struct Student{
	bool isR = false;
	int num;
	void input(int i){
		cin >> num;
	}
	bool operator < (const Student &o) const{
		return num > o.num;
	}
}a[maxn * maxn];
void change(int &c, int &r, int n){
	if(c % 2){
		if(r == n) c++;
		else r++;
	} else {
		if(r == 1) c++;
		else r--;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) a[i].input(i);
	a[1].isR = true;
	sort(a + 1, a + n * m + 1);
	for(int i = 1, c = 1, r = 1; i <= n * m; i++){
		if(a[i].isR == true){
		 	cout << c << ' ' << r << endl;
		 	return 0;
		}
		change(c, r, m);
	}
	return 0;
} 
