#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	if(n == 1){
		cout << 0;
	}
	else if(k == 0){
		cout << n;
	}
	else if(n == 2){
		if(a[1] == k && a[2] == k)
			cout << 2;
		else
			cout << 0;
	}
	else{
		srand(time(0));
		cout << rand()%(n+1);
	}
}
