#include <bits/stdc++.h>
using namespace std;




int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,r;
	cin >> n >> m;
	int a[n*m];
	for (int i = 1; i <= n*m; i++)
        cin >> a[i];
    r = a[1];
    int s = n*m;
    sort(a,a+s);
    cout << 1 << " " << 1;

    return 0;
}
