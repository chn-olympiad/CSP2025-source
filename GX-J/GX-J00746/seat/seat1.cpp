#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",%d);
	freopen("seat.out",%d);
	int n,m,p,maxn,k;
	k = 0;
	cin >> n >> m;
	p = n*m;
	int a[105],b[10][10];
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		
	}
	maxn = a[0];
	for(int i = 0;i<=p;i++){
		if(a[i]>a[0]){
            int t = a[0];
            a[0] = a[i];
            a[i] = t;
		}
	}

	for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            b[i][j] = a[k];
            for(int l = 0;l<=p;l++){
                k++;
            }
        }
	}
	for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(b[i][j] == maxn){
				cout << i  << " "<< j;
				}
        }
	}
	return 0;
}
