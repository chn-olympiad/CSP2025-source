#include<bits/stdc++.h>wW
using namespace std;
int a[15][15],n,m,b[105];
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)cin >> b[i];
	int num=b[1],cnt=0;
	sort(b+1,b+n*m+1);
	for(int i = 1;i <= m; i++){
		if(i%2){
			for(int j = 1; j <= n; j++){
				a[j][i]=b[n*m-cnt];
				cnt++;
			}
		}else{
			for(int j = n; j >=1; j--){
				a[j][i]=b[n*m-cnt];
				cnt++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(num==a[i][j])cout << j << " " << i;
		}
	}
	return 0;
}

