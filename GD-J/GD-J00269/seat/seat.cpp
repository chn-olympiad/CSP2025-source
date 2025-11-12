#include<bits/stdc++.h>
using namespace std;
int n, m, all, ans;
struct stu{
	int num, sco;
}a[101];
bool cmp(stu a, stu b){
	return a.sco > b.sco;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	all = n * m;
	for(int i = 1; i <= all; i++){
		cin >> a[i].sco;
		a[i].num = i;
	}
	sort(a + 1, a + all + 1, cmp);
	for(int i = 1; i <= all; i++){
		if(a[i].num == 1){
			ans = i;
			break;
		}
	}
	int w = (ans - 1) / n;
	int h = (ans - 1) % n;
	w++;
	if(w % 2 == 0){
		h = n - h;
	}else{
		h++;
	}
	cout << w << " " << h;
	return 0;
}
