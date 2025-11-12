#include <stdio.h>
#define SIZE 5010
int n,arr[SIZE];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d", arr + i);
	if(arr[1]+arr[2]>arr[3]&&arr[1]+arr[3]>arr[2]&&arr[3]+arr[2]>arr[1])putchar('1');
	else putchar('0');
}
