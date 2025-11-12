#include<bits/stdc++.h>
using namespace std;
long long m,n;
const int maxn = 200;
long long a[maxn][maxn],b[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m >> n;
	for(long long i = 1;i<=n*m;i++){
		cin >> b[i];
	}
	int cat = b[1];
	sort(b,b+(m*n)+1);
	long long x = 1,y = 1,sum = 1;
	for(long long i = m*n;i>=1;i--){
		a[x][y] = b[i];
		if(b[i] == cat){
			cout << y << " " << x;
		}
		x+=sum;
		if(x > n){
			sum = -1;
			x--;
			y++;
		}
		else if(x<1){
			sum = 1;
			x++;
			y++;
		}
	}
	return 0;
}
