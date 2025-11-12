#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,s = 1,p;
const int N = 100010;
int a[N],b[2000][2000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> k;
	a[0] = 99999;
	for(int i = 1; i < n*m; i++){
		cin >> a[i];
		for(int j = 1; j <= i; j++)
			if(a[j] > a[j-1]) swap(a[j],a[j-1]);
	}
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= m; j++){
				b[j][i] = a[s++];
				if(k > b[j][i]){
					x = j;
					y = i;
					p = 1;
					break;
				}
			}
			if(p == 1) break;
		}else{
			for(int j = m; j >= 1; j--){
				b[j][i] = a[s++];
				if(k > b[j][i]){
					x = j;
					y = i;
					p = 1;
					break;
				}
			}
			if(p == 1) break;
		}
	}
	cout << y <<' '<< x;
	return 0;
}
