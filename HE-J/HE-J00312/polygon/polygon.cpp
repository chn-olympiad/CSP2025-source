#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

const int mod =  998244353;

int n, a[5005], sum = 0;
//int b[5005];

void dfs(int dnl, int xjg, int zdz, int h){
	if(xjg >= 3 && h > zdz * 2) sum = sum + 1 >= mod ? (sum + 1) % mod : sum + 1;
//		cout << "\n  Si  \n" << dnl << "选了几个" << xjg << "最大值" << zdz << "和" << h << " " << sum << endl;
	
	
	if(dnl >= n) return ;
	
	for(int i = dnl + 1; i <= n; i++) dfs(i, xjg + 1, max(zdz, a[i]), h + a[i]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	dfs(0, 0, -1, 0);
	
	printf("%d", sum);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
5
1 2 3 4 5
*/
