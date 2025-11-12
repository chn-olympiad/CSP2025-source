#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l,a[10][10],num[100]={},cnt = 0;
	cin >> h >> l;
	for(int i = 0;i < h*l;i++){
		cin >> num[i];
	}
	int xiaoming = num[0];
	for(int j = 0;j < h*l;j++){
		for(int i = 0;i < h*l;i++){
			if(num[i] < num[i+1]){
				int b = num[i];
				num[i] += num[i+1];
				num[i+1] = b;
				num[i] -= num[i+1];
			}
		}
	}
	for(int i = 1;i <= l;i++){
		if(i % 2 == 1){
			for(int z = 1;z <= h;z++){
				if(num[cnt] == xiaoming){
					cout << i << " " << z;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				a[i][z] = num[cnt];
				cnt++;
			}
		}
		if(i % 2 == 0){
			for(int d = h;d >= 1;d--){
				if(num[cnt] == xiaoming){
					cout << i << " " << d;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				a[i][d] = num[cnt];
				cnt++;
			}
		}
	}
}
