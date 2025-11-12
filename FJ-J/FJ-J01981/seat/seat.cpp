#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],cnt = 0,ansx = 1,ansy = 1,f = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			if(i != 1 || j != 1){
				if(a[i][j] > a[1][1]){
					cnt++;
				}
			}
		}
	}
	while(cnt > 0){
		if(f == 1){
			ansx++;
			if(ansx > n){
				ansx--;
				ansy++;
				f = 0;
			}
		}
		else{
			ansx--;
			if(ansx == 0){
				ansx++;
				ansy++;
				f = 1;
			}
		}
		cnt--;
	}
	cout<<ansy<<" "<<ansx;
	return 0;
}
