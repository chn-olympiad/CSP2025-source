#include<bits/stdc++.h>
using namespace std;
int n , m ;
struct cj{
	int a1;
	int i1;
}a[105];
bool cmp(cj x,cj y){
	return x.a1 > y.a1;
}
int c , r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i].a1;
		a[i].i1 = i;
	}
	sort(a+1,a+1+n*m,cmp);
	for (int i = 1;i <= n * m;i++){
		if (a[i].i1 == 1){
			c = i / n;
			if (n * c != i){
				c++;
			}
			if (c % 2 == 1){
				r = i % n;
				if (r == 0) r += n;
			}else {
				r = n + 1 - i % n;
			}
		}
	}
	cout << c <<' ' << r;
	return 0;
}