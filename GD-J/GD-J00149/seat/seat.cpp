#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m;
int a[10005];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int t = a[1];
	int pos = 0;
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= n * m;i++){
		if (a[i] == t){
			pos = i;
			break;
		}
	}
	int u,v;
	if (pos % n == 0){
		u = pos / n;
	}else u = int(pos / n) + 1;
	if (u % 2 == 1){
		v = pos % n;
		if (v == 0) v = n;
	}else{
		v = pos % n;
		if (v == 0) v = n;
		v = n - v + 1;
	}
	cout << u << " " << v;
	return 0;
}
