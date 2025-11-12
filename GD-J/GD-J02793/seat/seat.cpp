#include<bits/stdc++.h>

using namespace std;

int n,m,k,a[105],x,y;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	k = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == k){
			k = i;
			break;
		}
	}
	x = (k + n - 1) / n;
	if(x % 2)y = (k - 1) % n + 1;
	else y = n - (k - 1) % n;
	cout << x << " " << y << endl;
	return 0;
}
