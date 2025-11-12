#include<bits/stdc++.h>
using namespace std;
const int maxn = 20, maxm = 20;
struct stu{
	int sc;
	int id;
};
bool cmp(stu a, stu b){
	return a.sc > b.sc ;
}

stu a[400];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].sc;
		a[i].id = i; 
	}
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		bool flag = false;
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				if(a[++cnt].id == 1){
					cout << i << " " << j << endl;
					break;
				}
			}
		}else{
			for(int j = n; j >= 1; j--){
				if(a[++cnt].id == 1){
					cout << i << " " << j << endl;
					break;
				}
			}
		}
	}
	return 0;
} 
