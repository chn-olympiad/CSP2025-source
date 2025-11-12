#include <bits/stdc++.h>
using namespace std;
bool cmp(int a1, int b1){
	return a1 > b1;
}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[110];
	for (int i = 1;i <= n * m;i ++){
		cin >> a[i];
	}
	int R = a[1];
	sort(a + 1, a + n*m + 1, cmp);
	int seat;
	for (int i = 1;i <= n * m;i ++) 
		if (a[i] == R) {
			seat = i;
			break;
		}
	int l = (seat + (n - 1))/n;
	
	
	int h = 1;
	if (l % 2){
		for (int i = (l - 1) * n + 1;i < l * n + 1; i ++){
			if (a[i] == R) {
				
				h = i % n;
				if(h == 0) h = n;	
				break;
			}
		}
	}
	else{
		h = n;
		for (int i = l * n;i > (l - 1) * n; i --){
			if (a[i] == R) {
				h = i % n;	
				if(h == 0) h = 1;
				break;
			}
			else h --;
		}
	}
	cout << l << ' ' << h;
	return 0;
}
