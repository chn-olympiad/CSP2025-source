#include<bits/stdc++.h>
using namespace std;
int m,n,a[15][15],g[110],c,ans;
bool p( int x,int y ){
	return x > y; 
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> c;
    g[1] = c;
    for( int i = 2;i <= m * n;i++ ){
    	cin >> g[i];
	}
	sort(g + 1,g + m * n + 1,p);
	for( int i = 1;i <= m * n;i++ ){
		if( g[i] == c ){
			ans = i;
			break;
		}
	}
	int cc = (ans - 1) / n + 1,rr;
	if( cc % 2 == 0 ){
		rr = n - ans % n + 1;
	}
	else{
		rr = (ans - 1) % n + 1;
	}
	cout << cc << ' ' << rr;
    return 0;
}
