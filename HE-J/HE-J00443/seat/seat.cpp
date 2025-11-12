#include <bits/stdc++.h>
using namespace std;
int a[1001];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,goal,goalnum;
	cin >> n >> m;
	int sumstu = n * m;
	for (int i = 1;i <= sumstu;i++){
		cin >> a[i];
		if (i == 1){
			goal = a[i];
		}
	}
	sort(a + 1,a + sumstu + 1,cmp);
	for (int i = 1;i <= sumstu;i++){
		if (a[i] == goal){
			goalnum = i;
			break;
		}
	}
	if (goalnum <= n){
		cout << 1 << " " << goalnum;
	}else if (goalnum % n == 0){
		cout << goalnum / n << " ";
		if ((goalnum / n) % 2 == 0) {
			cout << 1;
		}else {
			cout << n;
		}
	}else if((goalnum / n ) % 2 == 1){
		cout << goalnum / n + 1 << " ";
		int yvshu = goalnum % n;
		cout << n - yvshu + 1;
	}else{
		cout << goalnum / n + 1 << " " << goalnum % n;	
	}
	
	return 0;
}
