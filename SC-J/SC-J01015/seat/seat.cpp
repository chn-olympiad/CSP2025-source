#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int a[N], n, m;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int xx = 0;
	int nm = n * m;
	for(int i = 1;i <= nm;i ++){
		scanf("%d", &a[i]);
	}
	xx = a[1];
	
	int q = 0;
	for(int i = 1;i <= nm;i ++){
		if(a[i] >= xx)q ++;
	}
	
	int ans = q / n;
	if(q % n != 0)ans ++;
	printf("%d ", ans);
	
	int sum = q % n;
	if(sum == 0)sum = n;
	
	if(ans % 2 == 1){
		printf("%d\n", sum);
	}
	else{
		printf("%d\n", n - sum + 1); 
	}
	
	return 0; 
}