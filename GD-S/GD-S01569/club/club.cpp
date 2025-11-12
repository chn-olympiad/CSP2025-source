#include <iostream>

using namespace std;

int main(){
	int n;
	int t;
	int a[100000][5];
	int c[5] = {0};
	int cnt[10000] = {0};
	cin >> t;
	for (int p = 0;p < t;p++){
		cin >> n;
		for (int i = 0;i < n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for (int i = 0;i < n;i++){
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3]){
				if (c[1] <= (n / 2)){
					c[1]++;
					cnt[p] += a[i][1];
				}else{
					if (a[i][2] > a[i][3]){
						if (c[2] <= (n / 2)){
							c[2]++;
							cnt[p] += a[i][2];
						}else{
							c[3]++;
							cnt[p] += a[i][3];
						}
					}else{
						if (c[3] <= (n / 2)){
							c[3]++;
							cnt[p] += a[i][3];
						}
					}
				}
			}else if (a[i][2] > a[i][1] && a[i][2] > a[i][3]){
				if (c[2] <= (n / 2)){
					c[2]++;
					cnt[p] += a[i][2];
				}else{
					if (a[i][1] > a[i][3]){
						if (c[1] <= (n / 2)){
							c[1]++;
							cnt[p] += a[i][1];
						}else{
							c[3]++;
							cnt[p] += a[i][3];
						}
					}else{
						if (c[3] <= (n / 2)){
							c[3]++;
							cnt[p] += a[i][3];
						}
					}
				}
			}else if (a[i][3] > a[i][2] && a[i][3] > a[i][1]){
				if (c[3] <= (n / 2)){
					c[3]++;
					cnt[p] += a[i][3];
				}else{
					if (a[i][1] > a[i][2]){
						if (c[1] <= (n / 2)){
							c[1]++;
							cnt[p] += a[i][1];
						}else{
							c[2]++;
							cnt[p] += a[i][2];
						}
					}else{
						if (c[2] <= (n / 2)){
							c[2]++;
							cnt[p] += a[i][2];
						}
					}
				}
			}else if (a[i][1] == a[i][2] && a[i][1] > a[i][3]){
				if (c[1] <= (n / 2) && c[1] < c[2]){
					c[1]++;
					cnt[p] += a[i][1];
				}else if (c[2] <= (n / 2)){
					c[2]++;
					cnt[p] += a[i][2];
				}else{
					c[3]++;
					cnt[p] += a[i][3];
				}
			}else if (a[i][3] == a[i][2] && a[i][1] < a[i][3]){
				if (c[3] <= (n / 2)){
					c[3]++;
					cnt[p] += a[i][3];
				}else if (c[2] <= (n / 2)){
					c[2]++;
					cnt[p] += a[i][2];
				}else{
					c[1]++;
					cnt[p] += a[i][1];
				}
			}else if (a[i][3] == a[i][1] && a[i][2] < a[i][3]){
				if (c[1] <= (n / 2)){
					c[1]++; 
					cnt[p] += a[i][1];
				}else if (c[3] <= (n / 2)){
					c[3]++;
					cnt[p] += a[i][3];
				}else{
					c[2]++;
					cnt[p] += a[i][2];
				}
			}else{
				if (c[1] <= (n / 2)){
					c[1]++;
					cnt[p] += a[i][1];
				}else if (c[3] <= (n / 2)){
					c[3]++;
					cnt[p] += a[i][3];
				}else{
					c[2]++;
					cnt[p] += a[i][2];
				}
			}
		}
    }
    for (int p = 0;p < t;p++){
    	cout << cnt[p] << endl;
	}
}
