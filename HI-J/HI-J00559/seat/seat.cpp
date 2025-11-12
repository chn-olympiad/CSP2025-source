#include<bits/stdc++.h>
using namespace std;
int a[1000]; 
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w",stdout);
	int n, m;
	cin >> n >> m;
	int my = 0, cnt = 0;
	for(int i = 1; i <= n*m;i++){
		cin >> a[i];
		if(i==1)my=a[1];
		if(a[i] > my) cnt++;
	}
	cnt++;
	int xx = (cnt+n-1)/n;
	int yy = cnt%n;
	if(yy==0)yy=n;
	if(xx%2 == 0) yy = n-yy+1;
	cout<<xx<<' '<<yy; 
	return 0;
}
