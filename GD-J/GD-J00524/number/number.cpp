#include<bits/stdc++.h> 
using namespace std;
int a[500];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;
	cin >> st;
	for(char c : st){
		int s = c - '0';
		if (s <= 9){
			a[s] += 1;
		}
	}
	for(int i = 9; i >= 0;i--){
		while(a[i] > 0){
			cout << i;
			a[i]--;
		}
	}
	return 0;
}
