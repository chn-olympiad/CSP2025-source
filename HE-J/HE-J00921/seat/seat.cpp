#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int a[maxn], b[maxn];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >>n >>m;
	int ming;
	cin >>a[1];
	ming=a[1];
	int cnt=1;
	for(int i=2; i<=n*m; ++i){
		cin >>a[i];
		if(a[i]>ming) cnt++;
	}
	cout <<(cnt-1)/n+1 <<" ";
	if((cnt-1)/n%2) cout <<m-(cnt-1)%n;
	else cout <<(cnt-1)%n+1;
	return 0;
}
