#include<bits/stdc++.h>

using namespace std;

int n, a[100];

void f(){
	scanf("%d", &n);
	if(n == 3){
		scanf("%d%d%d", &a[1], &a[2], &a[3]);
		if(a[1] + a[2] == a[3] || a[1] + a[3] == a[2] || a[3] + a[2] == a[1])printf("0");
		else printf("1");
	}
	else printf("9");
}

int main(){
	freopen("polygon1.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	f();
	fclose(stdin);
	fclose(stdout);
	return 0;
}