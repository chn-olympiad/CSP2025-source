#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],cnt;
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	long long l = n * m;
	for(int i = 1;i <= l;i++){
		cin >> a[i];
	}
	long long b = a[1];
	sort(a + 1,a + 1 + l,cmp);
	for(int i = 1;i <= l;i++){
		if(a[i] == b){
			cnt = i;
			break;
		} 
	}
	int c = cnt / n;
	int d = cnt % n;
	if(cnt == 1){
		cout << 1 << " " << 1;
		return 0; 
	}
	else if(c * n < cnt){
		c = c + 1;
		if(c % 2 != 0){
			cout << c << " " << d;
		}
		else{
			d = m - d + 1;
			cout << c << " " << d;
		}
	}
	else if(c * n == cnt){
		if(c % 2 == 0){
			cout << c << " " << 1;
		}
		else{
			cout << c << " " << n;
		}
	}
	return 0;
} 
