#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	int R;
	R=a[1];
	sort (a+1,a+n*m+1,greater<int>());
	int p=1;
	for (;p<=n*m;p++) 
		if (a[p]==R) break ;
	int x=(p-1)/n+1,y;
	if (x%2) {
		y=p-(x-1)*n;
	}else {
		y=x*n-p+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
