#include<bits/stdc++.h>
using namespace std;
string a;
int num[11];
bool oz = true;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for(int i = 0; i < a.size(); i++){
		if(a[i] <= '9' && a[i] >= '0'){
			num[a[i] - '0']++;
			if(a[i] != '0') oz = false;
		}
	}
	if(oz) num[0] = 1;
	for(int i = 9; i >= 0; i--){
		if(num[i] != 0){
			while(num[i]--) cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

