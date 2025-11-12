#include<bits/stdc++.h>
using namespace std;

int n,m,R;
int a[150];

bool cmp(int x,int y){
	return x > y;
}

int erfen(){
	int l = 1,r = n* m;
	while(l < r){
		int mid = (l + r) >> 1;
		if(a[mid] == R) return mid;
		else if(a[mid] > R) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	R = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int w = erfen();
	int x = (w - 1) / n + 1;
	int y = 0;
	y = (w - 1) % m + 1;
	if(x % 2 == 0)
		y = m - y + 1;
	cout << x << " " << y;
	return 0;
}