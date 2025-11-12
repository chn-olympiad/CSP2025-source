#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10005];
int d[105][105];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);;
	cin >> n >> m;
	int sum = n*m;
	for(int i = 1; i <= sum; i++){
		cin >> a[i];
	}
	int r_ans = a[1];
	sort(a+1, a+sum+1, cmp);
	int k = 1;
	int num = ceil(m / 2.0);
	int cnt = 0;
	for(int i = 1; i <= num; i++){
		cnt++;
		for(int j = 1; j <= n; j++){
			d[j][cnt] = a[k++];
			if(d[j][cnt] == r_ans){
				cout << cnt << " " << j;
				return 0;
			}
		}
		cnt++;
		if(cnt > m){
			break;
		}
		for(int j = n; j >= 1; j--){
			d[j][cnt] = a[k++];
			if(d[j][cnt] == r_ans){
				cout << cnt << " " << j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
98 99 100 97
*/
