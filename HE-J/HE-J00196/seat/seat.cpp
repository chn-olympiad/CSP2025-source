#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int n, m;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int N = n*m;
	for(int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	int id = a[0];
	sort(a, a+N, cmp);
	for(int i = 0; i < N; i++){
		if(a[i] == id){
			id = i + 1;
			break;
		}
	}
	int h, l;
	if(id % n == 0){
		l = id / n;
		h = n;
		cout << l << ' ' << h;
		return 0; 
	}
	else{
		l = id / n + 1;
		if(l % 2 == 0){
			l --;
			h = n - (id - l * n) + 1;
			cout << l + 1 << ' ' << h;
			return 0;
		}
		else{
			l --;
			h = id - l * n;
			cout << l + 1 << ' ' << h;
			return 0;
		}
	}
	return 0;
} 
