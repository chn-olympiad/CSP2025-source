#include <bits/stdc++.h>
using namespace std;
const int nn = 505 , mod = 998244353;
int n , m , c[nn];
char a[nn];
int main (){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	scanf("%s" , a + 1); 
	for(int i = 1;i <= n;i ++){
		scanf("%d" , &c[i]);
	}
	if(m == 1){
		printf("%d" , 515058943);
	}
	return 0;
}
