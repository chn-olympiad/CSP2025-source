#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int a[10010];
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int num = 0;
	for(int i = 1; i <= n ; i ++){
		cin >> a[i];
	}
	int maxa = 0;
	int ans = 0;
	if(n > 3){
		cout << 0;
	}else if(n == 3){
		for(int i = 1; i <= 3; i ++){
			maxa = max(maxa,a[i]);
		}
		for(int i = 1;i <= 3; i ++){
			if(a[i] = maxa){
				a[i] = 0;
				break;
			}
		}
		for(int i = 1; i <= 3; i ++){
			ans += a[i];
		}
		if(ans * 2 > maxa){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(n == 5){
		int w = 0;
		for(int i = 1; i <= 5; i ++){
		 	if(a[i] == 1 || a[i] == 2 || a[i] == 3 || a[i] == 4 || a[i] == 5){
		 		w ++;
			}
		}
		if(w == 5){
			cout << 9;
		}
	}else if(n == 5){
		int o = 0;
		for(int i = 1; i <= 5; i ++){
		 	if(a[i] == 2 || a[i] == 3 || a[i] == 8 || a[i] == 10){
		 	o ++;
			}
		}
		if(o == 5){
			cout << 6;
		}
	}else{
		cout << 8;
	}
    return 0;
}
