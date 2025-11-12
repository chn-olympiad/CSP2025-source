#include<bits/stdc++.h>
using namespace std;

char a[10000001];
int n;

int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", a + 1);
	n = strlen(a + 1);
	
	for (int i = 1; i <= n - 1; i++){
		for (int j = 1; j <= n - 1; j++){
			if (a[j] < a[j + 1]){
				int f = a[j];
				a[j] = a[j + 1];
				a[j + 1] = f;
			}
			
		}
	}
	
	for (int i = 1; i <= n; i++){
		if (a[i] <= '9') printf("%c", a[i]);
	}
	
	return 0;
}
