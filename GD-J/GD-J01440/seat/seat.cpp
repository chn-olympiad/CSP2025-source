#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,b[110],a[110][110];
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m*n;i++){
		
		cin >> b[i];
		
	}
	ll f = b[1];
	ll c = 0;
	sort(b + 1,b + n * m + 1,cmp);

	for(int i = 1;i <= n*m;i++){
		if(f == b[i]){
			c = i;
		
			break;
		}
	}
	

	int con = 1;
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				a[j][i]=con;
				con++;
			}
		}else {
			for(int j = n;j >= 1;j--){
				a[j][i]=con;
				con++;
			}
		}
	}

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] == c){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
