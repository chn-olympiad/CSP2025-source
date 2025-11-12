#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
struct Student{
	bool r;
	int a;
} stu[105];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i += 1){
		cin >> stu[i].a;
	}
	stu[1].r = true;
	
	sort(stu + 1, stu + n * m + 1, 
	[](const Student& lft, const Student& rgt){
		return lft.a > rgt.a;
	});
	
	for (int c = 1; c <= m; c += 1){
		if (c & 1) for (int r = 1; r <= n; r += 1){
			k += 1;
			if (stu[k].r){
				cout << c << ' ' << r;
				return 0;
			}
		}else for (int r = n; r; r -= 1){
			k += 1;
			if (stu[k].r){
				cout << c << ' ' << r;
				return 0;
			}
		}
	}
	
	return 0;
}

