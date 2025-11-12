#include<iostream>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
string x;
int a[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> x;
	for(int i = 0;i < x.length();i++){
		if(x[i] >= '0' && x[i] <= '9'){
			a[x[i] - '0']++;
		}
	}
	bool flag = true;
	for(int i = 1;i <= 9;i++){
		if(a[i] != 0){
			flag = false;
		}
	}
	if(flag){
		cout << 0;
		return 0;
	}
	for(int i = 9;i >= 0;i--){
		while(a[i]--){
			cout << i;
		}
	}
	return 0;
}
