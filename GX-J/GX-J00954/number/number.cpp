# include <bits/stdc++.h>
using namespace std;

int Count[10];
string a;
int len;
int temp;

int main (){
	
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	cin >> a;
	
	len = a.size();
	
	for (int i = 0;i < len;i++){
		if (a[i] >= '0' && a[i] <= '9'){
			Count[a[i] - '0']++;
			temp++;
		}
	}
	
	for (int i = 9;i >= 0;i--){
		for (int j = 0;j < Count[i];j++){
			cout << i;
		}
	}
	
	return 0;
}
