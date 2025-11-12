#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main(){
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n*m;i++){
		scanf("%d", &a[i]);
	}
	int me = a[1], cnt=0;
	sort(a+1, a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i] == me){
			cnt = n*m-i+1;
			break;
		}
	}
	int row = (cnt-1)/n+1;
	printf("%d ", row);
	if(row%2){
		printf("%d ", (cnt-1)%n+1);
	}
	else{
		printf("%d\n", n-(cnt-1)%n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
