#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+10;
ll a[N];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	ll pm = 1;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
		if(i != 1 && a[i] > a[1]){
			pm++;
		}
	}
	ll ansx = 0,ansy = 0;
	ll cnt = 0;
	for(int i = 1;i <= m; ){
		for(int j = 1;j <= n;j++){
			cnt++;
			if(cnt == pm){
				ansx = i,ansy = j;
				break;
			}
		}
		i++;
		for(int j = n;j >= 1;j--){
			cnt++;
			if(cnt == pm){
				ansx = i,ansy = j;
				break;
			}
		}
		i++;
	}
	cout << ansx << " " << ansy;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
