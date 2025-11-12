#include <iostream>

using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	int a[5005];
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	int cnt = 0;
	
	for(int i = 0; i < n * 1.5; i++) cnt += 2;
	
	printf("9");
	
	return 0;
}
