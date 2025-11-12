#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sum = -100010,cnt = 0;
	cin >> t;
	int n[t];
	int arr[t];
	for(int k = 0;k < t;k++){
		cin >> n[k];
		int m = n[k];
		int a[m][3];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < 3;j++){
				cin >> a[i][j];
				if(a[i][j] > sum){
					sum = a[i][j];
				}
			}
			cnt += sum;
			sum = -100010;
		}
		m = 0;
		arr[k] = cnt;
		cnt = 0;
	}
	for(int i = 0;i < t;i++){
		cout << arr[i] << endl;
	}
	return 0;
}
