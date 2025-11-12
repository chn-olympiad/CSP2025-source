#include<bits/stdc++.h>
#define lc 2*k
#define rc 2*k+1
#define mid (l+r)/2
using namespace std;

const int N = 5200;
int n , a[N] , d[N] , tr[N*4];
int fun(int l , int r){
	int maxn = -1;
	for(int i = l;i <= r;i ++){
		maxn = max(maxn , a[i]);
	}
	return maxn;
}
void build(int k , int l , int r){
	if(l == r){
		tr[k] = a[l];
		return;
	}	
	build(lc , l , mid);
	build(rc , mid + 1 , r);
	tr[k] = max(tr[lc] , tr[rc]);
}
int query(int k , int l , int r , int x , int y){
	if(l >= x && r <= y)	return tr[k];
	int ans = 0;
	if(x <= mid) ans = max(ans , query(lc , l , mid , x , y));
	if(y > mid) ans = max(ans , query(rc , mid + 1 , r , x , y));
	return ans;
}
int main(){

	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	
	cin >> n;
	
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		int a , b , c;
		cin >> a >> b >> c;
		if((a + b + c) > 2*max(a , max(b , c))){
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	bool flag = true;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] != 1)	flag = false;
	}
	if(flag){
		cout << (n-1)*(n-2)/2;
		return 0;
	}
	flag = true;
	for(int i = 1;i <= n;i ++){
		if(a[i] != a[1])	flag = false;
	}
	if(flag){
		cout << (n-1)*(n-2)/2;
		return 0;
	}
	if(n <= 20){
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			d[i] = d[i-1] + a[i];
		}
		for(int i = 1;i <= n;i ++)
			for(int j = i+2;j <= n;j ++)
				if(d[j]-d[i-1] > 2*fun(i , j))	ans ++;
		cout << ans;
		return 0;
	}
	build(1 , 1 , n);
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		d[i] = d[i-1] + a[i];
	}
	for(int i = 1;i <= n;i ++)
		for(int j = i+2;j <= n;j ++)
			if(d[j]-d[i-1] > 2*query(1 , 1 , n , i , j))	ans ++;
	cout << ans;
	return 0;
}

