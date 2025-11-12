#include<bits/stdc++.h>

using namespace std;

int n, k, a[200010], is, os;

int main(){
	freopen("xor4.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 1)is++;
		else os++;
	}
	if(k == 1)printf("%d", is);
	else printf("%d", os);
	fclose(stdin);
	fclose(stdout);
	return 0;
}