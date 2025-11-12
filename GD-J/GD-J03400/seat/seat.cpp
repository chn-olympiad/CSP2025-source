#include<bits/stdc++.h>
using namespace std;
const int maxn = 225;
int n,m;
int a[maxn];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int res = a[1];
//	cout << res << endl;
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == res){
			res = i;
			break;
		}
	}
//	cout << res << endl;
	int x = res / n,y = res % n;
	if(y == 0){
		if(x & 1){
			cout << x << " " << n;
		}
		else cout << x << " " << 1;
	}
	else if((x + 1) & 1){
		cout << x + 1 << " " << y; 
	}
	else{
		cout << x + 1 << " " << n - y + 1;
	}
	return 0;
}
