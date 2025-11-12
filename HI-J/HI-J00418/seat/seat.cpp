#include<bits/stdc++.h>
using namespace std;
int n,m,e,f = 1,g = 0,sum = 1;
int a[15],b[15][15];
int cmp(int c,int d){
	return c > d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	e = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	while(f <= m){
		if(g == 0){
			for(int i = 1;i <= n;i++){
				b[i][f] = a[sum];
				sum++;
			}
			g++;
			f++;
		}
		if(g == 1){
			for(int i = n;i >= 1;i--){
				b[i][f] = a[sum];
				sum++;
			}
			g--;
			f++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == e){
				cout << j <<" "<< i;
				return 0;
			}
		}
	}
	return 0;
}
