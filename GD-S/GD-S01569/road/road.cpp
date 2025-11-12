#include <iostream>

using namespace std;

int main(){
	int n,m,k;
	int w[100000]; //第i条道路的修复费用 
	int c[100000]; //第j个乡镇进行城市化改造的费用 
	int a[100000][100000];//在第j个乡镇与原有的第i城市间建造道路的费用 
	int b[100000] = {0};
	int b2[100000] = {0};
	int cnt = 0;
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 0;j < k;j++){
		cin >> c[j];
		for (int l = 0;l < n;l++){
			cin >> a[j][l];
		}
	}
	for (int i = 0;i < n;i++){
		for (int j = 0;j < k;j++){
			if (b[j] == 0){
				if (w[i] >= a[j][i] + a[j][i + 1] + c[j]){
					cnt += a[j][i] + a[j][i + 1];
					b[j] = 1;
				}else{
					cnt += w[i];
					b2[i] = 1;
				}
			}else{
				if (w[i] >= a[j][i] + a[j][i + 1] + c[j]){
					cnt += a[j][i] + a[j][i + 1];
					b[j] = 1;
				}else{
					cnt += w[i];
					b2[i] = 1;
				}
			}
		}
	}
}
