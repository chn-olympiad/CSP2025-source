#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[105], p;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(p==a[i]){
			p=i;
			break;
		}
	}
	int x=(p-1)/n+1,y=(p-1)%n+1;
	if(x%2){
		cout << x << " " << y;
	}else{
		cout << x << " " << n-y+1;
	}
	return 0;
}
