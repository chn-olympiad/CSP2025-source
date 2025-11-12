#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[105];
	int s[15][15];
	freopen("seat.in","r",stdin);
	freopen("seat.out",'w',stdout);
    int m,n;
    cin >> n >> m;
    for (int i=1;i<=m*n;i++){
    	cin >> a[i];
	}
	int b;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			b=max(b,a[i]);
			if (b==a[1]){
				cout << s[i][j];
			}
		}
	}
	return 0;
	//±£´æÊ± ½â×¢ÊÍ 
}
