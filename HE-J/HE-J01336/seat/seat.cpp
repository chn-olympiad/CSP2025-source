#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	bool f;
	int sco;
}a[105];
bool cmp(node x,node y){
	return x.sco > y.sco;
}
int h,l;
int num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i].sco;
	a[1].f = 1;
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i].f == 1){
			num = i;
			break;
		}
	}
	if(num % n == 0){
		l = num / n;
	}
	else l = num / n + 1;
	if(l % 2 == 1){
		h = num - (l - 1) * n;
	}
	else{
		h = num - (l - 1) * n;
		h = n - h + 1;
	}
	cout << l << " " << h;
	return 0;
}
