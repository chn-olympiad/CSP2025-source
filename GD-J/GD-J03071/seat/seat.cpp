//wonder:100pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
int c[15][15];
bool cmp(int a,int b){
	return a > b;
}
void work(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int pos = 0;
	int r = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == r){
			pos = i;
			break;
		}
	}
	int cnt = 0;
	for(int j = 1;j <= m;j++){
		if(j % 2){
			for(int i = 1;i <= n;i++){
				c[i][j] = a[++cnt];
				if(a[cnt] == r){
					cout << j << " " << i;
					return;
				}
			}
		}
		else{
			for(int i = n;i >= 1;i--){
				c[i][j] = a[++cnt];
				if(a[cnt] == r){
					cout << j << " " << i;
					return;
				}
			}
		}
	}
	return;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t = 1;
//	cin >> t;
	while(t--){
		work();
		if(t) cout << endl;
	}
}

