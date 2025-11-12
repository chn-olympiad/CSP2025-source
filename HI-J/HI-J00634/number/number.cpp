#include <bits/stdc++.h>
using namespace std;
string n;
long long a[9];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n.size();i++){
		if(n[i] > '9' || n[i] < '0') continue;
		else a[n[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--){
		while(a[i] >= 1){
			cout << i;
			a[i]--;
		}
	}
	return 0;
} 
