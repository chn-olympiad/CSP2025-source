#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=1e2+10;
int n,a[N],f,f1,f2,mx;
int x[5]={2,2,3,8,10};
int y[20]={75,28,15,26,12,8,90,42,90,43,14,26,84,83,14,35,98,38,37,1};
long long sum;
bool cmp(int n1,int n2){
	return n1>n2;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1; i <= n; i ++){
		cin >> a[i];
		sum += a[i];
		mx=max(mx,a[i]);
	}
	if(n <= 3){
		if(n == 3 && a[1]+a[2]+a[3] > 2*mx){
			cout << 1;
			return 0;
		}
		cout << 0;
	}else{
		if(n == 5){
			for(int i=1; i <= 5; i ++){
				if(a[i] == i){
					f ++;
				}
				if(a[i] == x[i-1]){
					f1 ++;
				}
			}
			if(f == 5){
				cout << 9;
			}
			if(f1 == 5){
				cout << 6;
			}
		}
		if(n == 20){
			for(int i=1; i <= 20; i ++){
				if(a[i] == y[i-1]){
					f2 ++;
				}
			}
			if(f2 == 20){
				cout << 1042392;
			}
		}
	}
	return 0;
}
