#include<bits/stdc++.h>
using namespace std;
int num[15];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int j = 0;
	for(int i = 0 ; i < a.size() ; i++){
		if(48 <= a[i] && a[i] <= 58)
			num[a[i] - 48]++;
	}
	for(int i = 9 ; i >= 0 ; i--){
		j = num[i];
		for(int k = 1 ; k <= j ; k++){
			cout << i;
		}
	}
	return 0;
}
