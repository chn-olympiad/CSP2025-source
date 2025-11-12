#include<bits/stdc++.h>
using namespace std;
int a[500010],k,n,cnt;
bool b[500010][25],c[500010];
void t2(){
	for(int i = 0;i < n;i++){
		int c = a[i];
		int j = 0;
		while(c){
			b[i][j] = c % 2;
			c = c / 2;
			j++;
		}
	}
	return;
}
int f(int o,int u,int l){
	for(int i = 24;i >= 0;i--){
		if(i == 0);
	}
}
int main(){
	bool po = 1,pl = 1;
	int hk = 0;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] == k){
			cnt++;
			c[i] = 1;
		}
		if(a[i] == a[i + 1] && i < n - 1 && a[i] == 1){
			po = 1;
		}else{
			po = 0;
		}
		if(a[i] < 2 && pl){
			pl = 1;
		}else{
			pl = 0;
		}
		if(a[i] == 0){
			hk++;
		}
	}
	if(po){
		cout << n;
		return 0;
	}else if(pl){
		if(k == 1){
			cout << n - hk;
		}else{
			cout << hk;
		}
	}
	t2();
	int i = 2;
	while(i <= n){
		for(int j = 0;j + i - 1 < n;j++){
			int sum = 0;
			for(int l = 0;l < i;l++){
				sum = f(a[j + l],sum,j + l);
			}
			if(sum == k){
				cnt++;
			}
		}
		i++;
	}
	return 0;
}
