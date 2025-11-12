#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],k;

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	
	cin >> n >> m >> k;
	a[1] = k;
	for(int i=2;i<=n*m;i++)cin >> a[i];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[(i-1)*m+j]==k)cout << i << " " << j;
		}
	}
	
	return 0;
}
