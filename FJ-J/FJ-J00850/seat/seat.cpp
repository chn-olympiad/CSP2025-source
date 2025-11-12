#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
struct node{
	int num;
	int cj;
};
node a[N];
int n, m;
int c, r;
bool cmp(node a, node b){
	return a.cj > b.cj;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i].cj;
		a[i].num=i;
	}
	sort(a+1, a+1+n*m, cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i].num==1){
			if(i%n==0){
				c=i/n;
			}else{
				c=i/n+1;
			}
			int e = 2*n;
			if(i%e<=n){
				r=i%e;
			}else{
				r=i%e;
				r=e-r+1;
			}
			cout << c << " " << r;
			return 0;
		}
	}
	return 0;
}
