#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10; 

int t, n, res, a[3][N], am[N], ind[N], tot[3], use[3];

int get_min(int pos){
	int min_num = 1e5;
	for(int i = 0; i < 3; i++) 
		if(a[i][pos] < min_num) 
			min_num = a[i][pos];
	return min_num;
}

int get_max(int pos){
	int max_num = 0, k;
	for(int i = 0; i < 3; i++) 
		if(a[i][pos] > max_num && use[i] == 0) 
			max_num = a[i][pos], k = i;
	return k;
}

bool compare(int num1, int num2){
	return a[am[num1]][num1] > a[am[num2]][num2];
}

void init(){
	res = 0;
	for(int i = 0; i < 3; i++) use[i] = 0, tot[i] = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d%d", a[0] + i, a[1] + i, a[2] + i), ind[i] = i;
	for(int i = 1; i <= n; i++){
		int k = get_min(i);
		res += k;
		a[0][i] -= k, a[1][i] -= k, a[2][i] -= k;
		am[i] = get_max(i);
	}
	sort(ind + 1, ind + n + 1, compare);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		init();
		for(int i = 1; i <= n; i++){
			res += a[am[ind[i]]][ind[i]];
			tot[am[ind[i]]]++;
			if(tot[am[ind[i]]] == n / 2){
				use[am[ind[i]]] = 1;
				for(int j = i + 1; j <= n; j++) am[ind[j]] = get_max(ind[j]);
				sort(ind + i + 1, ind + n + 1, compare);
			} 
		}
		printf("%d\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}