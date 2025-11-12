#include <bits/stdc++.h>
using namespace std;

#define int long long
#define db double
#define pii pair<long long, long long>
#define endl "\n"

const int MXN = 20;

int n,m;
int scr[MXN*MXN];

signed main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	   
	ios::sync_with_stdio(0);
	cin.tie(0);
	   
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++){
    	cin >> scr[i];
	}
	
	int scr0 = scr[1];
	int cnt = 0;
	for(int i = 1; i <= n*m; i++){
		if(scr[i] > scr0){
			cnt++;
		}
	}
	//cout << cnt << ' ';
	
	cnt = cnt+1;
	int c = cnt/n + 1;
	int r = cnt%n;
	if(r == 0){
		r = n;
		cnt--;
	}
	if(c%2 == 0){
		r = n+1 - r;
	}
	cout << c << ' ' << r;
	   
	return 0;
 }

