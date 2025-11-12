#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int cnt = 0,num[100000];
	cin >> a;
	if(a.size() == 1){
		cout << a;
		return 0;
	}
	for(int i = 0;i <= a.size();i++){
		if(a[i] - 48 >= 0 && a[i] - 48 <= 9){
			num[cnt] = int(a[i]);
			cnt++; 
		}
	}
	for(int j = 0;j < cnt;j++){
		int yl = 0;
		for(int i = 0;i < cnt;i++){
			if(num[i] < num[i+1]){
				int b = int(num[i]);
				num[i] += num[i+1];
				num[i+1] = b;
				num[i] -= num[i+1];
				yl++;
			}
		}
		if(yl == 0){
			continue;
		}
	}
	for(int i = 0;i < cnt;i++){
		cout << num[i] - 48;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

