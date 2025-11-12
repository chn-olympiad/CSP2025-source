#include<bits/stdc++.h>
using namespace std;
int n,k;
bool flag;
bool t;
const int N = 5e5+5;
int a[N],w[N];
int sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		if(a[i] != 1) flag = 1;
		if(a[i] != k) t = 1;
	}
	if(flag == 0){
		cout << n;
		return 0;	
	}
	if(t == 0){
		cout << n;
		return 0;
	}
	if(k == 0){
		for(int i = 1;i <= n;i++){
			if(a[i] == 0) sum++;
		}
		cout << sum;
		return 0;
	}else{
		for(int i = 2;i <= n;i++){
			if(a[i] == 0 && a[i-1] == 1 || a[i] == 1 && a[i-1] == 0){
				sum++;
				a[i] = -1;
				a[i-1] = -1;
			}
		}
		cout << sum;
		return 0;
	}
	return 0;
}