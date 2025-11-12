#include<bits/stdc++.h>
using namespace std;

int n, k, a[500001], sum, b[500001], top;
bool ok[10000001];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int x = 0;
	for(int i = 1; i <= n; i++){
		x ^= a[i];
		if(x == k || ok[x ^ k]){
			sum++;
			for(int j = 1; j <= top; j++)
				ok[b[j]] = false;
			top = 0;
			x = 0;
		}
		else{
			if(!ok[x])
				b[++top] = x;
			ok[x] = true;
		}
	}
	printf("%d\n", sum);
	return 0;
}
