#include<bits/stdc++.h>
using namespace std;
int n, m;
int r, rp;
struct data{
	int cj;
	int pm;
}a[100];
int cmp(data a, data b){
	if(a.cj > b.cj){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i].cj;
	}
	r = a[1].cj;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1;i <= n * m;i++){
		a[i].pm = i;
		if(a[i].cj == r){
			rp = a[i].pm;
		}
	}
	int h, l = 1;
	while(rp - n > 0){
		rp -= n;
		l++;
	}
	cout << l << " ";
	if(l % 2 != 0){
		cout << rp;
	}else{
		cout << n - rp + 1;
	}
	return 0;
}
