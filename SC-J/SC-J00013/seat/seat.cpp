#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
int a[N];
int n, m, scr, c, r;
bool flag = true;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	scr = a[1];
	sort(a + 1, a + n * m + 1); 
	c = r = 1;
	for(int i = 1; i <= n * m; i++){
		if(a[i] == scr){
			printf("%d %d", c, r);
			return 0;
		}
		if(c == m || c == 0){
			flag = !flag;
			r++;
		}
		if(flag){
			c++; 
		}else{
			c--;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}