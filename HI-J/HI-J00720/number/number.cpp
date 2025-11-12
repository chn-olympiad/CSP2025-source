#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin >> n;
	for(long long i = 0; i < n.size(); i++){
		if(n[i] >= '0' && n[i] <= '9'){
			int x = n[i]-'0';
			a[x]++;
		}
	}
	for(int i = 9; i >= 0; i--){
		if(a[i] > 0){
			long long c = a[i];
			while(c--){
				cout << i;
			}
		}
	}
	return 0;
}
