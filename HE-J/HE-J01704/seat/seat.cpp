#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+5;
int n,m,a[N],r;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
		if(i == 1) r = a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	int l = 1,h = 0;
	for(int i = 1;i <= n*m;i++){
		h++;
		if(h > 2*n){
			h -= 2*n;
			l += 2;
		}
		if(a[i] == r) break;
	}
	if(h > n) h = 2*n-h+1,l++;
	cout << l << " " << h;
	return 0;
}
