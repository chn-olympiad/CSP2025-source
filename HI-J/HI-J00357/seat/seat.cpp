#include <bits/stdc++.h>
using namespace std;
int a[105][105],cnt[10005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> cnt[i];
	}
	int k = cnt[1];
	sort(cnt+1,cnt+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++){
		if (((i-1) / n + 1) % 2 == 1){
			a[(i-1) / n + 1][(i-1) % n + 1] = cnt[i];
		}
		else{
			a[(i-1) / n + 1][n * ((i-1) / n + 1) + 1 - i] = cnt[i];
		}
	}
	int flag = 0;
	for (int i = 1;i <= n && flag == 0;i++){
		for (int j = 1;j <= m && flag == 0;j++){
			if (a[i][j] == k){
				cout << i <<  " " << j;
				flag = 1;
			}		
		}
	}
	return 0;
}
