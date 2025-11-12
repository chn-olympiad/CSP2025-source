#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[110];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	int x = a[1],p;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]) p = i;
	}
	int y;
	if(p%n==0) y = p / n;
	else y = p / n + 1;//上取整，第几列
	if(y%2==0) cout << y << " " << n*y-p+1;
	else cout << y << " " << p-n*y+n;
	


	return 0;
}

