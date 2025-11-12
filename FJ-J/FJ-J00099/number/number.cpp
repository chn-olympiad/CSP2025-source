#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
string b;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,b);
	for(int i = 0; i < b.size(); i++){
		if(b[i] >= '0' && b[i] <= '9') a[b[i]-48]++;
	}
	for(int i = 9; i >= 0; i--){
		if(a[i] > 0){
			for(int j = 1; j <= a[i]; j++){
				cout << i;
			}
		}
	}
	return 0;
}
