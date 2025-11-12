#include<bits/stdc++.h>
using namespace std;
struct Mark{
	int s,uid;
}a[1000];
int n,m, p;
bool cmp(Mark a, Mark b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i].s;
		a[i].uid=i;
	}
	sort(a+1, a+1+n*m, cmp);
	for(int i=1; i<=n*m; i++)
		if(a[i].uid==1){
			p=i;
			break;
		}
	cout << p/n+min(p%n,1) << " ";
	cout<< ((p/n+min(p%n,1))%2==1?(p%n==0?n:p%n):m-p%n+1);
	return 0;
}
