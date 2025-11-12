#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,greater<>());
	int x = lower_bound(a+1,a+1+n*m,r,greater<>())-a;
	int col = (x+n-1)/n;
	if(col%2==1) cout<<col<<" "<<(x-1)%n+1;
	else cout<<col<<" "<<n-(x-1)%n;
	return 0;
}