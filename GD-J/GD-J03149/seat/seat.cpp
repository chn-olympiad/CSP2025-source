#include <bits/stdc++.h>
using namespace std; 
int n, m;
int tot;
int a[1002];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	tot = n * m;
	for (int i = 0; i < tot; i++){
		scanf("%d", &a[i]);
	}
	int tar = a[0];
	int tarw = 0;
	
	for (int i = 0; i < tot; i++){
		for (int j = 0; j < tot; j++){
			if (a[j] <= a[j + 1]){
				swap(a[j], a[j + 1]);
			}
		}
	}
	
	 for (int i = 0; i < tot; i++){
		if (a[i] == tar){
			tarw = i;
			break;
		}
	}
	tarw++;
	int lie = tarw / n;
	int hang = tarw - lie * n;
	int anshang = 0;
	if (tarw % n != 0){
		lie++;
	}
	if (lie % 2 == 0){
		anshang = n - hang + 1;
	}
	if (lie % 2 != 0){
		anshang = hang;
	}
	printf("%d %d\n", lie, anshang);
	return 0;
}
