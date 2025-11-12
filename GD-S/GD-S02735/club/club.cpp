#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 110005
#define int long long
int T;
int a[MAXN][5];
bool cmpA(int x, int y){
	if(min(a[x][1] - a[x][2], a[x][1] - a[x][3]) != min(a[y][1] - a[y][2], a[y][1] - a[y][3]))
		return min(a[x][1] - a[x][2], a[x][1] - a[x][3]) > min(a[y][1] - a[y][2], a[y][1] - a[y][3]);
	return a[x][1] > a[y][1];
	//差异度大的放前面
	//差异度为离第二满意的距离 
}
bool cmpB(int x, int y){
	if(min(a[x][2] - a[x][1], a[x][2] - a[x][3]) != min(a[y][2] - a[y][1], a[y][2] - a[y][3]))
		return min(a[x][2] - a[x][1], a[x][2] - a[x][3]) > min(a[y][2] - a[y][1], a[y][2] - a[y][3]);
	return a[x][2] > a[y][2];
}
bool cmpC(int x, int y){
	if(min(a[x][3] - a[x][1], a[x][3] - a[x][2]) != min(a[y][3] - a[y][1], a[y][3] - a[y][2]))
		return min(a[x][3] - a[x][1], a[x][3] - a[x][2]) > min(a[y][3] - a[y][1], a[y][3] - a[y][2]);
	return a[x][3] > a[y][3];
}
void solve(){
	int n, ans = 0;
	vector<int> A, B, C;
	memset(a, 0, sizeof(a));
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])//vector里存的是编号 
			A.push_back(i);
		else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
			B.push_back(i);
		else
			C.push_back(i);
	}
	sort(A.begin(), A.end(), cmpA);
	sort(B.begin(), B.end(), cmpB);
	sort(C.begin(), C.end(), cmpC);
	
	for(int i = 0; i < min(n / 2, (long long)A.size()); i++)
		ans += a[A[i]][1];
	for(int i = n / 2; i < A.size(); i++)
		ans += max(a[A[i]][2], a[A[i]][3]);
	
	for(int i = 0; i < min(n / 2, (long long)B.size()); i++)
		ans += a[B[i]][2];
	for(int i = n / 2; i < B.size(); i++)
		ans += max(a[B[i]][1], a[B[i]][3]);

	for(int i = 0; i < min(n / 2, (long long)C.size()); i++)
		ans += a[C[i]][3];
	for(int i = n / 2; i < C.size(); i++)
		ans += max(a[C[i]][1], a[C[i]][2]);

	printf("%lld\n", ans);
}
signed main(void){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while(T--){
		solve();
	}
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
