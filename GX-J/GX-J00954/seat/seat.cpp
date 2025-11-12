# include <bits/stdc++.h>
using namespace std;

int n, m;

struct A{
	int a;
	int id;
}seat[105];

bool cmp (A a, A b){
	return a.a > b.a;
}

int main (){
	
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 0;i < n * m;i++){
		cin >> seat[i].a;
		seat[i].id = i;
	}
	
	sort (seat, seat + n * m, cmp);
	
	if (n == 1 && m == 1){
		cout << "1 1";
		return 0;
	}
	else if (n == 1){
		for (int i = 0;i < n * m;i++){
			if (seat[i].id == 0){
				cout << i + 1 << " 1";
				return 0;
			}
		}
	}
	else if (m == 1){
		for (int i = 0;i < n * m;i++){
			if (seat[i].id == 0){
				cout << "1 " << i + 1;
				return 0;
			}
		}
	}
	else {
		int x = 0, y = 0;
		int temp = 0;//0 = down 1 = up
		
		for (int i = 0;i < n * m;i++){
			
			if (seat[i].id == 0){
				cout << y + 1 << " " << x + 1;
				return 0;
			}
			
			
			if (x == n - 1 && temp == 0){
				y++;
				temp = 1;
				continue;
			}
			if (x == 0 && temp == 1){
				y++;
				temp = 0;
				continue;
			} 
			
			if (temp == 0){
				x++;
			}
			else {
				x--;
			}
		}
	}
	
	return 0;
}
