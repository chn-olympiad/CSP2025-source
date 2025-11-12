#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int a[N];

bool cmp(int x,int y){
	return x > y;
}

int main() {
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	cin >> n >> m;
	
	int r;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i]; 
		if(i == 1){
			r = a[i];
		}
	}
	
	sort(a+1,a+(n*m)+1,cmp);
	
	int f;
	for(int i = 1; i <= n*m; i++){
		if(r == a[i]){
			f = i;
			break;
		}
	}
	
	cout << ceil(f*1.0 / n) << ' ';
	int yu = (f+n) % n;
	if(yu == 0){
		yu += n;
	}
	if(int(ceil(f*1.0 / n)) % 2 == 1){
		cout << yu;
	} else{
		cout << n-yu+1;
	}
	
	return 0;
}
