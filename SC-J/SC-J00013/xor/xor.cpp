#include <iostream>
using namespace std;
const int N = 5e5 + 5;
int n, k, cnt1, cnt2;
int a[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 1){
			cnt1++;
		}
		if(a[i] == 0){
			cnt2++;
		}
	}
	if(k == 0 && cnt1 == n){
		printf("0\n");
	}else if((k == 0 && (cnt2 == n || cnt1 + cnt2 == n)) || (k == 1 && cnt1 == n)){
		printf("%d\n", n);
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}