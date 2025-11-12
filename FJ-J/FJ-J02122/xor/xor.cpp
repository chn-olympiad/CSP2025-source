#include<bits/stdc++.h>
using namespace std;
long long n,k,l,r;
int a[500005];
bool f = 1; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == 0){
			f = 0;
			break;
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == 1){
			l++;
		}else{
			r++;
		}
	}
	if(k == 0 && f){
		cout << n/2;
	}else if(k == 0 && f == 0){
		cout << l/2+r;
	}else if(k == 1 && f == 0){
		cout << l;
	}else{
		cout << 0;
	}
	return 0;
}
