#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
int s[15][15],a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	r = a[1];
	c = n*m;
	sort(a+1,a+n*m+1);
	for(int i = 1;i<=n;i++){
		if(i%2==1){
			for(int j = 1;j<=m;j++){
				s[i][j] = a[c];
				if(a[c] == r){
					cout<< i << " " << j;
				}
				c--;
			}
		}else{
			for(int j = m;j>=1;j--){
				s[i][j] = a[c];
				if(a[c] == r){
					cout<< i << " " << j;
				}
				c--;
			}
		}
	}
	return 0;
}
