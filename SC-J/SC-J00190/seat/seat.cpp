#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d", &n, &m);
	int a[101];
	for(int i = 1;i <= n * m;i++){
		scanf("%d", a[i]);
	}
	int s = 0;
	for(int i = 2;i <= n * m;i++){
		 if(a[i] > a[1]){
		 	s++;
		 }
	}
	printf("%d ", s / n + 1);
	if((s / n + 1) % 2 == 0){
		printf("%d", n - s % n + 1);
	}
	else{
		printf("%d", s % n);
	}
	return 0;
}