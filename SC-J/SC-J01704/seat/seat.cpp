#include<bits/stdc++.h>
using namespace std;
int sc[105] , pm = 0 , xh = 0;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> sc[i];
	xh = sc[1];
	sort(sc + 1 , sc + n * m + 1 , greater<int>());
	for(int i = 1;i <= n * m;i++) if(sc[i] == xh) pm = i;
	int r = pm / n + 1 , c = pm % n;
	if(r % 2 == 0 && c == 0) r-- , c = m - c;
	if(r % 2 == 0 && c != 0) c = m + 1 - c;
	cout << r << " " << c;
	fclose(stdin);
	fclose(stdout);
}