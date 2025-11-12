#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;
int a[N * N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[++cnt]);
		}
	}
	int vr = a[1];
	sort(a + 1, a + cnt + 1, cmp);
	int i = 1, j = 1, op = 0;
	cnt = 1;
	while(a[cnt] != vr){
		cnt++;
		if(op == 0){
			if(i == n){
				j++;
				op = 1;
			}else i++;
		}else{
			if(i == 1){
				j++;
				op = 0;
			}else i--;
		}
	}
	printf("%d %d\n", j, i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}