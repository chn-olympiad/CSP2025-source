#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[12];
int check;
char s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(cin >> s){
		if(s>='0' && s<='9'){
			a[s-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i!=0 && a[i]>0)break;
		if(i==0){
			cout << 0 << '\n';
			return 0;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout << i;
		}
	}
	return 0;
}
