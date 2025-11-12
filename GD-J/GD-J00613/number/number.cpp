#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int x = s.length();
	int a[x];
	int b[x];
	for(int i = 0; i < x; i++){
		a[i] = -1;
		b[i] = -1;
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			//cout << s[i]<<" ";
			a[i] = s[i];
		}
		a[i] -= 48;
		//cout << a[i];
	}
	int m = 0;
	int c = 0;
	int cnt = 0;
	while(cnt != x -1){
		cnt = 0;
		for(int i = 0; i < x - 1; i++){
			if(a[i] < a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
		for(int i = 0; i < x-1; i++){
			if(a[i] >= a[i+1]){
				cnt++;
			}
			//cout <<"cnt:"<< cnt << " ";
		}
	}
	for(int i = 0; i < x; i++){
		if(a[i] >= 0){
			cout << a[i];
		}
	}
} 
