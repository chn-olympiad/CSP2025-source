#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1000005], j;
char c[1000005];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf ("%s", &c);
	for (auto s:c){
		if (s >= '0' && s <= '9') a[++j] = s - '0';
	}
	sort (a + 1, a + 1 + j);
	for (int i = j;i >= 1;i--){
		printf ("%d", a[i]);
	}
	return 0;
} 
